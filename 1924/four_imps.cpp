#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    k = (n + 1) / 2;
    if (k % 2 != 0)
        cout << "grimy";
    else
        cout << "black";
    return 0;
}