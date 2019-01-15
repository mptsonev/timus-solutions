#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int j = 0, force = 0, pos = 1;
    while (j < n - 2) {
        if (a[j] + a[j + 1] + a[j + 2] > force) {
            force = a[j] + a[j + 1] + a[j + 2];
            pos = j + 2;
        }
        j++;
    }
    cout << force << " " << pos;

    return 0;
}
