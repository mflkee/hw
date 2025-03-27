#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    // Разделяем студентов на группы
    vector<int> excellent, poor;
    for (int rating : ratings) {
        if (rating >= 90) {
            excellent.push_back(rating);
        } else if (rating < 60) {
            poor.push_back(rating);
        }
    }

    // Проверка на возможность формирования групп
    if (excellent.empty() || poor.empty()) {
        cout << "Impossible";
        return 0;
    }

    // Оставляем только три лучших отличника
    sort(excellent.begin(), excellent.end(), greater<int>());
    if (excellent.size() > 3) {
        excellent.resize(3);
    }

    // Расчет размеров подгрупп
    int num_excellent = excellent.size();
    int num_poor = poor.size();
    int base_size = num_poor / num_excellent; // Базовый размер подгруппы
    int remainder = num_poor % num_excellent; // Остаток

    // Формирование подгрупп
    vector<vector<int>> result;
    int start = 0;
    for (int i = 0; i < num_excellent; ++i) {
        int group_size = base_size + (i < remainder ? 1 : 0);
        if (start >= num_poor) {
            break; // Больше нет студентов для распределения
        }
        vector<int> group;
        group.push_back(excellent[i]); // Добавляем рейтинг отличника
        for (int j = 0; j < group_size && start + j < num_poor; ++j) {
            group.push_back(poor[start + j]);
        }
        result.push_back(group);
        start += group_size;
    }

    // Вывод результата
    for (const auto& group : result) {
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i != group.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
