#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> a;
    int n, k, i, m, l, p = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> k;
        a[k]++;
    }

    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> k;
        a[k]++;
    }

    cin >> l;
    for (i = 0; i < l; i++) {
        cin >> k;
        a[k]++;
        if (a[k] == 3)
            p++;
    }

    cout << p;

    return 0;
}
