#include <iostream>
#include <math.h>
#include <chrono>
using namespace std::chrono;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {  
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }
    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    auto naive = 100000;
    auto start = std::chrono::high_resolution_clock::now();
    auto fast = get_fibonacci_huge_fast(n,m);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<milliseconds>(stop - start).count();

    std::cout << "fast: " << fast << std::endl;
    std::cout << "naive: " << naive << std::endl;
    std::cout << "duration: " << duration << std::endl;

    if (naive != fast)
    {
        printf("Failed: Wrong answer \n");
    }       
    else{
        printf("OK: Right Answer \n");
    }
    if (duration >1000)
    {
        printf("Failed: Time limit exceded \n");
    }
    else{
        printf("Passed \n");
    }
    }
