#include <iostream>
using namespace std;
int main()
{

    int x, y, c;
    cin >> x >> y >> c;
    if (x + y < c)
        cout << "Impossible";
    else if (x + y == c)
        cout << x << " " << y;
    else if (x == 0)
        cout << 0 << " " << c;
    else if (y == 0)
        cout << c << " " << 0;
    else if (x >= c)
        cout << c << " " << 0;
    else if (y >= c)
        cout << 0 << " " << c;
    else if (x >= y)
        cout << x << " " << c - x;
    else
        cout << c - y << " " << y;

    return 0;
}