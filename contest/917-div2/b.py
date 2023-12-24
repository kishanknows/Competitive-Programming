import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    s = input()[:-1]
    res = [0] * n
    st = set()
    for i in range(n):
        st.add(s[i])
        res[i] = len(st)
    # print(res)
    print(sum(res))


for _ in range(int(input())):
    solve()
