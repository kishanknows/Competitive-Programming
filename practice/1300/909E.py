import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def int_input():
    return(int(input()))
def list_input():
    return(list(map(int,input().split())))
def string_input():
    s = input()
    return(list(s[:len(s) - 1]))
def int_with_spaces_input():
    return(map(int,input().split()))


T = int(input())
for t in range(T):
    n = int(input())
    a = list((map(int, input().split())))
    mini = min(a)
    max_ops = a.index(mini)
    sorted_count = 1
    j = n-1
    while j > 0 and a[j] >= a[j-1]:
        sorted_count += 1
        j -= 1
    if n - sorted_count > max_ops:
        print(-1)
    else:
        print(n-sorted_count)

