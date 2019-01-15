#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b && a % 2 == 0)
        cout << 0;
    else if (a == b && a % 2 == 1)
        cout << 1;
    else {

        if (a % 2 == 0)
            a++;
        cout << (b - a) / 2 + 1;
    }
    return 0;
}
