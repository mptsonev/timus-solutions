#include <iostream>
using namespace std;

int a[11];
int main(void)
{

    for (int i = 1; i <= 7; i++)
        cin >> a[i];

    for (int i = 1; i < 10; i++) {
        if (((a[2] + a[3] + a[4]) % 2 == a[5]) && ((a[1] + a[3] + a[4]) % 2 == a[6]) && ((a[1] + a[2] + a[4]) % 2 == a[7]))
            break;
        else {
            a[i] = (!a[i]);
            a[i - 1] = (!a[i - 1]);
        }
    }

    for (int i = 1; i <= 7; i++)
        cout << a[i] << " ";

    return 0;
}