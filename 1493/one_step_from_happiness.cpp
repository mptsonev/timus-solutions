#include <iostream>
using namespace std;
void convert(string b, int a[])
{

    for (int i = 0; i < b.length(); i++) {
        a[i] = b[i] - '0';
    }
}

bool isLucky(int a[])
{
    return (a[0] + a[1] + a[2] == a[3] + a[4] + a[5]);
}

void oneUp(int a[])
{
    int i = 5;
    while (a[i] == 9) {
        a[i] = 0;
        i--;
    }
    a[i]++;
}

void oneDown(int a[])
{
    int i = 5;
    while (a[i] == 0) {
        a[i] = 9;
        i--;
    }

    a[i]--;
}

int main()
{
    string n;
    cin >> n;
    int a[6];
    convert(n, a);
    oneDown(a);
    if (isLucky(a))
        cout << "Yes";
    else {
        oneUp(a);
        oneUp(a);
        if (isLucky(a))
            cout << "Yes";
        else
            cout << "No";
    }

    return 0;
}
