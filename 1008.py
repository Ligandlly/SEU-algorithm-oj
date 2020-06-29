group_number = int(input())
for _ in range(group_number):
    height = [int(i) for i in input().split(' ')[1:]]
    dp = {}
    dp[0] = 1

    for i in range(1, len(height)):
        dp[i]= 1
        for j in range(0, i):
            if height[i] <= height[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    print(max(dp.values()), end=' ')

    l = [height[0]]
    for h in height[1:]:
        if h > l[-1]:
            l.append(h)
        else:
            i = len(l) - 1
            while i >= 0 and l[i] > h:
                i -= 1
            i += 1
            l[i] = h
    print(len(l))
