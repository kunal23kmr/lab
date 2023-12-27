def number(x):
    def sub(y):
        print(x-y)
    return sub


result =number(100)
result(50)

result=number(40)
result(70)