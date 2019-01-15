#include <iostream>
#include <cmath>
#include <iomanip>
#include <stack> 
using namespace std;

int main() {
  unsigned long long int n;
  std::stack<double> first;
  while (cin>>n) {
    first.push(sqrt(n));
  }
  setprecision(2);
  while(!first.empty()) {
    cout << fixed << first.top() << endl;
    first.pop()
  }
}