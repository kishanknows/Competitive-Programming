import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    h = list(map(int, input().split()))
    h.append(1)
    tmp = []
    mp = []
    for i in range(n):
        if h[i]%h[i+1] == 0:
            tmp.append(a[i])
        else:
            tmp.append(a[i])
            mp.append(tmp)
            tmp = []
    if len(tmp) != 0:
        mp.append(tmp)
    res = 0
    for sublist in mp:
        sum = 0
        i = 0; j = 0
        while(j < len(sublist)):
            sum += sublist[j]
            while(sum > k):
                sum -= sublist[i]
                i += 1
            res = max(res, j - i + 1)
            j += 1
    print(res)
