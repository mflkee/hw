#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция для проверки соответствия строки маске
bool matchesMask(const vector<int>& row, const string& mask) {
    if (row.size() != mask.size()) {
        return false; // Размер строки не совпадает с размером маски
    }
    for (size_t i = 0; i < row.size(); ++i) {
        char maskChar = mask[i];
        int value = row[i];
        if (maskChar == '+' && value <= 0) {
            return false;
        } else if (maskChar == '-' && value >= 0) {
            return false;
        } else if (maskChar == '.' && value != 0) {
            return false;
        }
        // '*' всегда соответствует любому значению
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Считываем маску
    string mask;
    cin >> mask;

    // Считываем матрицу
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Подсчитываем количество строк, соответствующих маске
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (matchesMask(matrix[i], mask)) {
            ++count;
        }
    }

    // Выводим результат
    if (count > 0) {
        cout << count;
    } else {
        cout << "No lines with mask\n";
    }

    return 0;
}
