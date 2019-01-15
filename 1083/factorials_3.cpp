#include <iostream>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    int k = str.length();
    long int fact = 1;
    int minimum;
    if (n % k == 0)
        minimum = k;
    else
        minimum = n % k;

    while (n >= minimum) {
        fact *= n;
        n -= k;
    }
    cout << fact;

    return 0;
}