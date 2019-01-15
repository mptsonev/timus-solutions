#include <iostream>
#include <cstring>
using namespace std;

int keyPress(char a)
{
    if (a == '.')
        return 1;
    if (a == ',')
        return 2;
    if (a == '!')
        return 3;
    if (a == ' ')
        return 1;
    return (a - 'a') % 3 + 1;
}

int main()
{
    string a;
    getline(cin, a);
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
        sum += keyPress(a[i]);
    cout << sum;

    return 0;
}
