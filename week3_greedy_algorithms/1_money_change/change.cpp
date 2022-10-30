#include <iostream>
#include <math.h>
int get_change_naive(int m) {
  //write your code here
  // assuming denominations are 1,2,5,10
  if (m <=1)
  return m;
  
  int num= 0;
  int n = 0;
  for(int i = m; i >= 1; i--)
  {
    if(i%10 == 0)
    {
      std::cout << i << " ";
      num = 10;
    }
    else if(i%5 == 0)
    {
      std::cout << i << " ";
      num = 5;
    }
    else if(i%2 == 0)
    {
      std::cout << i << " ";
      num = 2;
    }
    else
    {
      std::cout << i << " ";
      num = 1;
    }
    i-=num;
    n++;

  }
  return n;
}

int get_change_fast(int m) {
  //write your code here
  // assuming denominations are 1,2,5,10
  int n_10 = floor(m/10);
  int n_5 = floor((m-(10*n_10))/5);
  int n_2 = floor((m-((10*n_10) + (5*n_5)))/2);
  int n_1 = m-((10*n_10) + (5*n_5) + (2*n_2));
  std::cout<< m << " " << n_10 << " " << n_5 << " " << n_2 << " " << n_1 << std::endl;
  int n = n_10 + n_5 + n_2 + n_1;
  return n;
}

int get_change_recursive(int m) {
  //write your code here
  // assuming denominations are 1,2,5,10
  int n = 0;
  if(m<=1)
    return m;

  if(m/10 > 0)
  {
    m-=10;
  }
  else if(m/5 > 0)
  {
    m-=5;
  }
  else if(m/2 > 0)
  {
    m-=2;
  }
  else
  {
    m-=1;
  }
  
  return 1 + get_change_recursive(m);
}

int get_change_min(int m) {
  //write your code here
  // assuming denominations are 1,2,5,10
  int denominations[4] = {10,5,2,1};
  int n = 0;
  while(m>0)
  {
    if(m>=10)
    {
      m-=10;
      n++;
    }
    else if(m>=5)
    {
      m-=5;
      n++;
    }
    else if(m>=2)
    {
      m-=2;
      n++;
    }
    else
    {
      m-=1;
      n++;
    }
  }
  return n;
}
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change_fast(m) << '\n';
  std::cout << get_change_recursive(m) << '\n';
  std::cout << get_change_min(m) << '\n';
}
