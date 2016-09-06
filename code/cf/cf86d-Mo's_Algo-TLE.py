#py3
import math
from functools import *
#
n,t = map(int,input().split(' '))
a = list(map(int,input().split(' ')))
a = [0] + a
#
block_size = int(math.sqrt(n))
query = []
ans = [0 for x in range(t + 10)]
for p in range(t):
    l,r = map(int,input().split(' '))
    query.append((l,r,p))
def cp(a,b):
    if a[0] / block_size == b[0] / block_size:
        return a[1] < b[1]
    else:
        return a[0] / block_size < b[0] / block_size
        
query = sorted(query,key=cmp_to_key(cp))
# 用了functool里的函数把cmp转换为key，py3里已经不支持直接cmp了
#
L = 0
R = 0
S = 0
cnt = [0 for x in range(1000010)]
def Add(pos):
    global S
    S += a[pos] * (2 * cnt[a[pos]] + 1)
    cnt[a[pos]] += 1
def Del(pos):
    global S
    S -= a[pos] * (2 * cnt[a[pos]] - 1)
    cnt[a[pos]] -= 1
for l,r,idx in query:
    while l < L:
        L -= 1
        Add(L)
    while r > R:
        R += 1
        Add(R)
    while l > L:
        Del(L)
        L += 1
    while r < R:
        Del(R)
        R -= 1
    ans[idx] = S
for x in range(t):
    print(ans[x])
