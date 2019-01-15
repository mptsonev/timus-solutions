#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int a, b, s_1 = 0, s_2 = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        s_1 += a;
        s_2 += b;
    }
    s_1 += k;
    if (s_1 >= s_2 + (n + 1) * 2)
        cout << s_1 - s_2 - (n + 1) * 2;
    else
        cout << "Big Bang!";
    return 0;
}