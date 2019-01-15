#include <iostream>
#include <cmath>
using namespace std;

void getAnswer(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] + b[j] == 10000) {
            cout << "YES";
            return;
        }
        if (a[i] + b[j] < 10000)
            i++;
        else
            j++;
    }
    cout << "NO";
    return;
}

int main()

{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    getAnswer(a, b, n, m);

    return 0;
}
