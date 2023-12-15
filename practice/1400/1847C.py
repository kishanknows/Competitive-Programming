import sys

input = sys.stdin.readline


class TrieNode:
    def __init__(self) -> None:
        self.val = 0
        self.left = None
        self.right = None


class Trie:
    def __init__(self) -> None:
        self.root = TrieNode()

    def insert(self, val):
        tmp = self.root
        for i in range(31, -1, -1):
            bit = val & (1 << i)
            if bit:
                if not tmp.right:
                    tmp.right = TrieNode()
                tmp = tmp.right
            else:
                if not tmp.left:
                    tmp.left = TrieNode()
                tmp = tmp.left
        tmp.val = val

    def query(self, val):
        tmp = self.root
        for i in range(31, -1, -1):
            bit = val & (1 << i)
            if bit:
                if tmp.left:
                    tmp = tmp.left
                elif tmp.right:
                    tmp = tmp.right
            else:
                if tmp.right:
                    tmp = tmp.right
                elif tmp.left:
                    tmp = tmp.left
        return tmp.val ^ val


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    res = -float("inf")
    trie = Trie()
    xor = 0
    for num in a:
        xor ^= num
        trie.insert(xor)
        res = max(res, xor)
    xor = 0
    for num in a:
        xor ^= num
        res = max(res, trie.query(xor))
    print(res)


for _ in range(int(input())):
    solve()
