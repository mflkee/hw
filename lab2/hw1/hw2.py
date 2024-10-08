word = 'test'

length = len(word)

if length % 2 == 0:
    middle_left = length // 2 - 1
    middle_right = length // 2
    middle_chars = word[middle_left:middle_right + 1]
else:
    middle = length // 2
    middle_chars = word[middle]

print(middle_chars)
