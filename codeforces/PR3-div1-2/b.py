import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    tmp = list(a)
    div = True
    res = 1
    while div:
        flag = True
        for num in a:
            if num % 2 != 0:
                flag = False
                div = False
                break
        if flag:
            res *= 2
            for i in range(n):
                a[i] = a[i] // 2
    odd = True
    for num in a:
        if num % 2 == 0:
            odd = False
            break
    if odd:
        cur = 4
        while True:
            flag = True
            st = set()
            for num in a:
                st.add(num % cur)
            if len(st) == 2:
                res *= cur
                break
            cur *= 2
    else:
        res *= 2
    print(res)
    # for i in range(n):
    #     tmp[i] = tmp[i] % res
    # print(tmp)


for _ in range(int(input())):
    solve()
