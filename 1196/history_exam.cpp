#include <iostream>
#include <map>
using namespace std;

bool isMember(int a[], int x, int n)
{
    int right = n, left = 0;
    while (right >= left) {
        int mid = (right + left) / 2;
        if (a[mid] == x)
            return true;
        if (x < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

int main()
{
    int ans = 0;

    int n, m;

    cin >> n;
    int plist[n], s_year;
    for (int i = 0; i < n; i++)
        cin >> plist[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s_year;
        if (isMember(plist, s_year, n))
            ans++;
    }

    cout << ans;

    return 0;
}
