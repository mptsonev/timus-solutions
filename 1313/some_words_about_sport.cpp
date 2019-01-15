#include <iostream>
using namespace std;
int main()
{
    int n, a[102][102];
    cin >> n;
    for (int i = 0; i <= n; i++) {
        a[0][i] = 101;
        a[i][n + 1] = 101;
        a[i][0] = 101;
        a[n + 1][i] = 101;
        a[n + 1][n + 1] = 101;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int down = 1, right = 1;
    while (down != n + 2 && right != n + 2) {
        int _down = down, _right = right;
        while (a[_down][_right] != 101) {
            cout << a[_down][_right] << " ";
            _down--;
            _right++;
        }
        if (down < n)
            down++;
        else
            right++;
    }

    return 0;
}