#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned long fibonacci[n];
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 1)
            fibonacci[i] = 2;
        else
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    cout << fibonacci[n - 1];

    return 0;
}
