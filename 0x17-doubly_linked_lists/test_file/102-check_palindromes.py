#!/usr/bin/python3
def check_palindrome(n):
    string = str(n)
    return string == string[::-1]

p_list = []
for i in range(999, 99, -1):
    for j in range(i + 1, 99, -1):
        product = i * j
        if check_palindrome(product):
            p_list.append(product)

print(max(p_list))
