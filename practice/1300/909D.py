import sys
from collections import Counter
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

def solve():
    int(input())
    mp = Counter(i for i in list(map(int, input().split())))
    print(sum(x*(x-1)//2 for x in mp.values() if x >= 2) + mp.get(1, 0)*mp.get(2, 0))

T = int(input())
for t in range(T):
   solve()