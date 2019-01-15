#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, k;
    cin >> k >> n;
    int a[101];
    int current = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (current + a[i] - k <= 0)
            current = 0;
        else
            current = current + a[i] - k;
    }
    cout << current;
    return 0;
}
