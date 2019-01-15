#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double ans = 0;
    int input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        ans += input;
    }
    cout << fixed << setprecision(6) << (double)ans / n;

    return 0;
}
