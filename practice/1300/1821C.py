import sys
from types import GeneratorType
input = sys.stdin.readline

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

@bootstrap
def dfs(step, s, n, id):
    is_equal = True
    for i in range(id, n-step, step):
        print(s[i], end='')
        if s[i] != s[i+step]:
            is_equal = False
            break
    if is_equal: yield 0
    even = yield dfs(step*2, s, n, id)
    odd = yield dfs(step*2, s, n, id+step)
    yield 1 + min(even, odd)

for _ in range(int(input())):
    s = input()
    n = len(s)-1
    st = ""
    for i in range(n):
        if s[i] == s[i+1]:
            continue
        st += s[i]
    print(dfs(1, st, len(st), 0))
    print('--------------------------')