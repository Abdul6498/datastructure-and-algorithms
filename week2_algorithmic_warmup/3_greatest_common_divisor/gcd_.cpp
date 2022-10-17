#include <iostream>
#include <math.h>
#include <chrono>
using namespace std::chrono;

int gcd_naive(int a, int b)
{
    int best = 0;
    for(int i = 1; i<a+b; i++)
    {
        if(a%i == 0 && b%i == 0)
        {
            best = i;
        }
    }
    return best;
}

int EuclidGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    // std::cout << a << " , " << b << std::endl;
    int a_p = a % b;
    return EuclidGCD(b,a_p);
}

int main() {
    int a, b;
    std::cout << "GCD" << std::endl;
    std::cin >> a >> b;
    
    int naive = gcd_naive(a, b);
    std::cout << naive << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    int fast = EuclidGCD(a,b);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<milliseconds>(stop - start).count();
    std::cout << "fast: " << fast << std::endl;
    if (naive != fast)
    {
        printf("Failed: Wrong answer \n");
    }       
    else{
        printf("OK: Right Answer \n");
    }
    if (duration >1)
    {
        printf("Failed: Time limit exceded \n");
    }
    else{
        printf("Passed \n");
    }
            

    return 0;
}
