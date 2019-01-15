#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, m, dummy;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = 0;
    for (int i = 0; i < m; i++) {
        cin >> dummy;
        a[dummy]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(2) << (double)(a[i]) / (double)(m)*100.0 << "%" << endl;
    }

    return 0;
}
