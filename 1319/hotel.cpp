#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n][n];
    int counter = 1;
    int down = 0, right = n - 1;
    while (down <= n - 1 && right >= 0) {
        int _down = down, _right = right;
        while (_down < n && _right < n) {
            a[_down][_right] = counter;
            counter++;
            _down++;
            _right++;
        }
        if (right >= 1)
            right--;
        else
            down++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
