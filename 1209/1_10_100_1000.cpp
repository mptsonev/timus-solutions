#include <iostream>
#include <math.h>
using namespace std;
int main()

{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        unsigned long int number = (sqrt(8.0 * k - 7) - 1) / 2;
        if (1 + (number * (number + 1)) / 2 == k)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    return 0;
}
