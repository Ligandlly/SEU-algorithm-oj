def f(s, mul_number, dp):
    if (s, mul_number) in dp:
        return dp[(s, mul_number)]
    if mul_number == 0:
        return int(s)
    result = 0
    for i in range(1, len(s)):
        tmp = int(s[:i]) * f(s[i:], mul_number - 1, dp)
        if tmp > result:
            result = tmp
    dp[(s, mul_number)] = result
    return result

group_number = int(input())
for _ in range(group_number):
    __, mul_number, n = input().split(' ')
    mul_number = int(mul_number)
    dp = {}
    print(f(n, mul_number, dp))