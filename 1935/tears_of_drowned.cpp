#include <iostream>
using namespace std;
int main()
{
    int a[101], n, max = 0, sum = 0, ix = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
            ix = i;
        }
    }
    a[ix] *= 2;

    for (int i = 0; i < n; i++)
        sum += a[i];
    cout << sum;
    return 0;
}