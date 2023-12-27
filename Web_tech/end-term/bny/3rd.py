def solve(N, A, Q, Queries):
    result = []

    for query in Queries:
        if query[0] == 1:
            L, X = query[1], query[2]
            A[L - 1] = X
        elif query[0] == 2:
            L, R, X = query[1], query[2], query[3]
            found = False
            for P in range(L - 1, R):
                if A[P] <= X:
                    result.append(P + 1)
                    found = True
                    break
            if not found:
                result.append(-1)
    return result


def main():
    N = int(input("Enter the length of the list A: "))
    A = list(map(int, input("Enter the elements of the list A separated by space: ").split()))
    Q = int(input("Enter the number of queries: "))
    Queries = []

    for _ in range(Q):
        query = tuple(
            map(int, input("Enter a query as space-separated values: ").split()))
        Queries.append(query)

    results = solve(N, A, Q, Queries)

    print("Results:")
    for i in results:
        print(i)


if __name__ == "__main__":
    main()
