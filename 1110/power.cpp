#include <iostream>
#include <cmath>
using namespace std;

int Convert(int base, int power, int modulos)
{
    int ans = 1;
    for (int i = 0; i < power; i++) {

        if (i == 0)
            ans *= base;
        else
            ans = ((ans % modulos) * base) % modulos;
    }
    return ans;
}

int main()
{
    int n, m, y, br = 0;
    int curr;
    cin >> n >> m >> y;

    for (int x = 0; x < m; x++) {

        if (Convert(x, n, m) == y) {
            if (br == 0)
                cout << x;
            else
                cout << " " << x;
            br = 1;
        }
    }

    if (br == 0)
        cout << -1;

    return 0;
}
