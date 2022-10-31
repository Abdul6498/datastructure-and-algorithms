#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using std::vector;

double get_optimal_value_naive(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  if (capacity == 0 || weights.size() == 0){
    return 0;
  }
  auto it = std::minmax_element(values.begin(), values.end());
  int max_idx = std::distance(values.begin(), it.second);
  int amount = min(weights[max_idx],capacity);
  if(weights[max_idx] < capacity)
    capacity -= amount;
  std::cout << "max_idx: " << max_idx << " "<< weights[max_idx]<< " " << values[max_idx]<< " " << amount <<std::endl;
  value = values[max_idx] * (amount/weights[max_idx]);
  weights.erase(weights.begin() + max_idx);
  values.erase(values.begin() + max_idx);

  return value + get_optimal_value_naive(capacity,weights,values);
}

void show_vector(vector<int> values)
{
  for (int i = 0; i < values.size(); i++) {
    std::cout << values[i] << " ";
  }
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  //show_vector(values);
  double optimal_value = get_optimal_value_naive(capacity, weights, values);

  //std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
