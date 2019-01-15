#include <iostream>
using namespace std;

int main()
{
    int n;
    long int sum = 0;
    cin >> n;
    if (n >= 1)
        sum = (1 + n) * n / 2;
    else
        sum = (1 + n) * (2 + (-1) * n) / 2;
    cout << sum;

    return 0;
}