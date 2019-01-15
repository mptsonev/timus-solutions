#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (2 * a + 39 >= 2 * b + 40)
        cout << 2 * a + 39;
    else
        cout << 2 * b + 40;
    return 0;
}