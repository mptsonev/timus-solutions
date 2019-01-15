#include <iostream>
using namespace std;

void printA(int n)
{

    for (int i = 1; i <= n; i++) {
        cout << "sin(" << i;
        if (i % 2 == 0 && i != n)
            cout << "+";
        else if (i % 2 == 1 && i != n)
            cout << "-";
    }
    for (int i = 1; i <= n; i++)
        cout << ")";
}

void printS(int n)
{
    for (int i = 2; i <= n; i++) {
        cout << "(";
    }
    for (int i = 1; i <= n; i++) {
        printA(i);
        cout << "+" << n - i + 1;
        if (i != n)
            cout << ")";
    }
}

int main()
{
    int n;
    cin >> n;
    printS(n);

    return 0;
}