from math import ceil, log2


def solve(N, K, parents, earning_members):
    h = ceil(log2(N))
    jump = [parents] + [[0] * N for _ in range(h - 1)]
    jump[0][0] = 0
    have_salary = [False] * N
    ans = []

    for i in range(1, h):
        for j in range(N):
            jump[i][j] = jump[i - 1][jump[i - 1][j]]

    def getKthAncestor(node, k):
        v = 0
        while k:
            if k & 1:
                node = jump[v][node]
            k >>= 1
            v += 1
        return node

    for i in earning_members:
        l, r = 0, N - 1
        if have_salary[i]:
            continue
        res = i
        while l <= r:
            m = (l + r + 1) >> 1
            node = getKthAncestor(i, m)
            if have_salary[node]:
                r = -1
            else:
                res = node
                l = m + 1
        have_salary[res] = True
        ans.append(res)

    return ans


N = int(input())
K = int(input())
parents = list(map(int, input().split()))
earning_members = list(map(int, input().split()))
out_solve = solve(N, K, parents, earning_members)
print(''.join(map(str, out_solve)))
