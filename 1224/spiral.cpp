#include <iostream>
using namespace std;
int main()
{
    unsigned long int m, n;
    cin >> n >> m;
    if (n * 2 - 2 < m * 2 - 1)
        cout << n * 2 - 2;
    else
        cout << m * 2 - 1;
    return 0;
}