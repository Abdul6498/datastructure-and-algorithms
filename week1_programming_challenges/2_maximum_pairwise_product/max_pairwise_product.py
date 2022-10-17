import sys
import time
import numpy as np
import random
def max_pairwise_product(numbers):
    n = numbers.shape[0]
    max_product = 0
    for first in range(n):
        for second in range(first + 1, n):
            max_product = max(max_product,
                numbers[first] * numbers[second])

    return max_product

def MaxPairwiseProduct(num):
    if(num.shape[0] > 2):
        sorted_val = np.sort(abs(num))
        pair_product = sorted_val[num.shape[0]-1] * sorted_val[num.shape[0]-2]
        return pair_product

    else:
        return num[0] * num[1]

if __name__ == '__main__':
    # _ = int(input())
    # input_numbers = list(map(int, input().split()))
    len = int(sys.argv[1])
    seed = int(sys.argv[2])
    np.random.seed(seed)
    input_numbers = np.random.randint(-len,len,len)

    naive = max_pairwise_product(input_numbers)
    start = time.perf_counter()
    fast = MaxPairwiseProduct(input_numbers)
    end = time.perf_counter()
    print(end-start)

    if (naive != fast):
        print("Failed: Wrong answer")
    if (end-start) > 1:
        print("Failed: Time limit exceded")
