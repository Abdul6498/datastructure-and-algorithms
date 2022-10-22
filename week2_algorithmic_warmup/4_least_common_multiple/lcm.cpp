#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <algorithm>
#include <string>

using namespace std::chrono;

std::vector<int> factors(int num)
{
  int temp = num;
  std::vector<int> v;
  int i = 1;
  for (i = 2; i <= temp; i++)
  {
    if(temp%i == 0)
    {
      v.push_back(i);
      temp = temp/i;
      i = 1;
    }
      
  }
    return v;
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long vector_multi(std::vector<int>& v) {
  long long result = 1;
  for(int i = 0; i < v.size(); ++i)
  {
    result = result * v[i];
  }
  return result;
}
void print_vector(std::vector<int>& v) {
  for(int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
}
long long lcm_fast(int a, int b) {
  
  std::vector<int> a_fac = factors(a);
  std::vector<int> b_fac = factors(b);
  print_vector(a_fac);
  std::cout << std::endl;
  print_vector(b_fac);
  std::cout << std::endl;
  int len = 0;
  for(int i = 0; i < a_fac.size(); ++i)
  {
    for(int j= 0; j< b_fac.size(); j++)
    {
      if(a_fac[i] == b_fac[j])
      {
        b_fac[j] = 1;
        break;
      }
    }
  }
  print_vector(a_fac);
  std::cout << std::endl;
  print_vector(b_fac);
  std::cout << std::endl;
  long long result = vector_multi(a_fac) * vector_multi(b_fac);

  return (long long) result;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  auto naive = 100000;//lcm_naive(a, b);
  //std::cout << lcm_fast(a, b) << std::endl;
  //auto v = factors(a);
  auto start = std::chrono::high_resolution_clock::now();
  auto fast = lcm_fast(a,b);
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
   return 0;
}
