import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()[:-1]
    if(s.count('0') != s.count('1')):
        print(-1)
        continue
    i = 0
    res = []
    while(i < len(s)-i-1):
        if s[i] == s[-i-1]:
            if s[i] == '1':
                res.append(i)
                s = s[:i] + '01' + s[i:]
            else:
                res.append(len(s)-i)
                s = s[:len(s)-i] + '01' + s[len(s)-i:]
        i += 1
    print(len(res))
    for r in res: print(r, end=' ')
    print("")