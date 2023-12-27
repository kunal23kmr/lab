class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.construct_tree(arr, 0, self.n - 1, 0)

    def construct_tree(self, arr, start, end, index):
        if start == end:
            self.tree[index] = arr[start]
            return arr[start]

        mid = (start + end) // 2
        left = self.construct_tree(arr, start, mid, 2 * index + 1)
        right = self.construct_tree(arr, mid + 1, end, 2 * index + 2)
        self.tree[index] = left + right
        return self.tree[index]

    def update(self, start, end, index, i, value):
        if i < start or i > end:
            return

        self.tree[index] += value

        if start != end:
            mid = (start + end) // 2
            self.update(start, mid, 2 * index + 1, i, value)
            self.update(mid + 1, end, 2 * index + 2, i, value)

    def query(self, start, end, index, left, right):
        if left > end or right < start:
            return 0

        if left <= start and right >= end:
            return self.tree[index]

        mid = (start + end) // 2
        return self.query(start, mid, 2 * index + 1, left, right) + \
            self.query(mid + 1, end, 2 * index + 2, left, right)


def smallest_prime_factor(n):
    if n % 2 == 0:
        return 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return i
    return n


def Divisor_Queries(N, Q, a, Queries):
    segment_tree = SegmentTree(a)
    result = []

    for query in Queries:
        if query[0] == 1:
            l, r = query[1], query[2]
            for i in range(l - 1, r):
                d = smallest_prime_factor(a[i])
                x = (a[i]//d)-a[i]
                a[i] = a[i] // d
                segment_tree.update(0, N - 1, 0, i, x)
        elif query[0] == 2:
            l, r = query[1], query[2]
            total_sum = segment_tree.query(0, N - 1, 0, l - 1, r - 1)
            result.append(total_sum)
        elif query[0] == 3:
            i, k = query[1], query[2]
            old_value = a[i - 1]
            a[i - 1] = k
            segment_tree.update(0, N - 1, 0, i - 1, k - old_value)

    return result


# Example usage
N, Q = map(int, input().split())
a = list(map(int, input().split()))
Queries = []
for _ in range(Q):
    Queries.append(list(map(int, input().split())))

output = Divisor_Queries(N, Q, a, Queries)

# Print the result for each query of type 2
for value in output:
    print(value)
