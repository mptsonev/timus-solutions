#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.1415926
using namespace std;
int main()
{

    double len, r;
    cin >> len >> r;
    if (r <= len / 2)
        cout << setprecision(3) << fixed << PI * r * r;
    else if (sqrt(2) * len / 2 <= r)
        cout << setprecision(3) << fixed << len * len;
    else
        cout << setprecision(3) << fixed << PI * r * r - 4 * acos((len / r) / 2) * r * r + 2 * len * sqrt(r * r - (len * len) / 4);

    return 0;
}
