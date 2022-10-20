#include <iostream>
#include <chrono>
using namespace std::chrono;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit(int n) {  
    if (n <= 1)
        return n;
    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    return current;
}

int main() {
    int n;
    std::cin >> n;

    int naive = get_fibonacci_last_digit_naive(n);
    

    auto start = std::chrono::high_resolution_clock::now();
    int fast = get_fibonacci_last_digit(n);
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
    if (duration >1)
    {
        printf("Failed: Time limit exceded \n");
    }
    else{
        printf("Passed \n");
    }
    }
