#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << endl;
    for (int k = 1; k <= m; k++)
        cout << k * n + 1 << " ";

    return 0;
}
