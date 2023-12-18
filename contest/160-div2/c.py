import sys

input = sys.stdin.readline


def solve():
    m = int(input())
    count = [0 for _ in range(32)]
    for _ in range(m):
        a, b = map(int, input().split())
        if a == 1:
            count[b] += 1
        else:
            res = "YES"
            prev = 0
            cur = 0
            for i in range(32):
                cur = count[i] + prev
                bit = b & (1 << i)
                if bit and cur == 0:
                    res = "NO"
                    break
                elif bit:
                    prev = (cur - 1) // 2
                else:
                    prev = cur // 2

            print(res)


# for _ in range(int(input())):
solve()
