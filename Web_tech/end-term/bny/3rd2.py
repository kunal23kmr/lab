class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 1, 0, self.n - 1)

    def build(self, arr, v, tl, tr):
        if tl == tr:
            self.tree[v] = arr[tl]
        else:
            tm = (tl + tr) // 2
            self.build(arr, 2 * v, tl, tm)
            self.build(arr, 2 * v + 1, tm + 1, tr)
            self.tree[v] = min(self.tree[2 * v], self.tree[2 * v + 1])

    def update(self, v, tl, tr, pos, new_val):
        if tl == tr:
            self.tree[v] = new_val
        else:
            tm = (tl + tr) // 2
            if pos <= tm:
                self.update(2 * v, tl, tm, pos, new_val)
            else:
                self.update(2 * v + 1, tm + 1, tr, pos, new_val)
            self.tree[v] = min(self.tree[2 * v], self.tree[2 * v + 1])

    def query(self, v, tl, tr, l, r, x):
        if l > r:
            return float('inf')
        if self.tree[v] > x:
            return float('inf')
        if tl == tr and self.tree[v]<=x:
            return tl
        tm = (tl + tr) // 2

        if tm>=l and tm<=r:
            return min(self.query(2 * v, tl, tm, l, tm, x), self.query(2 * v, tm+1, tr, tm+1, tr, x))
        elif tm>r:
            return self.query(2 * v, tl, tm, l, tr, x)
        else:
            return self.query(2 * v, tl, tr, l, r, x)



def solve(N, A, Q, Queries):
    result = []
    segment_tree = SegmentTree(A)

    for query in Queries:
        if query[0] == 1:
            L, X = query[1], query[2]
            segment_tree.update(1, 0, N - 1, L - 1, X)
        elif query[0] == 2:
            L, R, X = query[1], query[2], query[3]
            P = segment_tree.query(1, 0, N - 1, L - 1, R - 1, X)
            if P==float('inf'):
                result.append(-1)
            else:
                result.append(P)

    return result


def main():
    N = int(input())
    A = list(
        map(int, input().split()))
    Q = int(input())
    Queries = []

    for _ in range(Q):
        query = tuple(
            map(int, input().split()))
        Queries.append(query)

    results = solve(N, A, Q, Queries)

    for i in results:
        print(i)


if __name__ == "__main__":
    main()
