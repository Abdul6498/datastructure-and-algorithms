# Python3
# n = int(input())

# if n<=1:
#     print(n)  
#     quit()

def fibo(n):
    a, b = 0, 1
    if n < 2:
        return n
    for _ in range(n-1):
        c = a + b
        b, a = c, b
    return c
    #print(c)

# fibo(n)
