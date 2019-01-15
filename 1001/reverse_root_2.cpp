#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double buff[128*1024];

int main() {
  unsigned long long int n;
  long long int i=0;
  while (cin>>n) {
    buff[i]=sqrt(n);
    i++;
  }
  setprecision(2);
  for (int j=i-1; j>=0; j--) cout<<fixed<<buff[j]<<endl;
  return 0;

}
