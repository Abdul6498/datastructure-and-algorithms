
from math import sqrt
from numbers import Real
import numpy as np
import time
import sys
path = path = "/home/abdul/datastructure-and-algorithms/Solutions"
sys.path.insert(0, path)
from fibonacci import fibo

def fibonacci_number(n):
    if n <= 1:
        return n

    return fibonacci_number(n - 1) + fibonacci_number(n - 2)

def fibonacci_fast(n):
    #number = (1/sqrt(5))*(((((1+sqrt(5))/2)**n))-(((1-sqrt(5)/2)**n)))
    prev_1 = 1 
    prev_2 = 0
    if n < 2:
        number = n
    else:
        for i in range(2,n+1):
            number = prev_1+prev_2
            prev_2 = prev_1
            prev_1 = number
    #print(number)
    return number

def test_solution():
    assert(fibonacci_fast(3) == 2)
    assert(fibonacci_fast(10) == 55)
    for n in range(20):
        assert(fibonacci_fast(n) == fibo(n))

if __name__ == '__main__':
    input_n = int(input())
    #print(fibonacci_number(input_n))
    # print(fibo(input_n))
    print(fibonacci_fast(input_n))
    # naive = fibonacci_number(input_n)
    test_solution()
    naive = fibo(input_n)
    start = time.perf_counter()
    fast = fibonacci_fast(input_n)
    end = time.perf_counter()
    print(naive, fast)

    if (naive != fast):
        print("Failed: Wrong answer")
    else:
        print("OK: Right Answer")
    if (end-start) > 1:
        print("Failed: Time limit exceded")
    else:
        print("Passed")
