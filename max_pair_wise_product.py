import sys

# generate random integer values
import numpy as np

def MaxPairwiseProduct(num):
    if(num.shape[0] > 2):
        sorted_val = np.sort(num)
        pair_product = sorted_val[num.shape[0]-1] * sorted_val[num.shape[0]-2]
        # print(sorted_val)
        # print(pair_product)
        return pair_product, sorted_val[num.shape[0]-1], sorted_val[num.shape[0]-2]

    else:
        return num[0] * num[1], num[0], num[1]

len = int(sys.argv[1])
seed = int(sys.argv[2])
np.random.seed(seed)
values = np.random.randint(-200,10e5,len)
#print(values)
product, num1, num2 = MaxPairwiseProduct(values)
print(product, num1, num2)