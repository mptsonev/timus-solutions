#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> a;
    int inpt, ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inpt;
        a[inpt]++;
        if (a[inpt] == 4) {
            ans++;
            a[inpt] = 0;
        }
    }
    cout << ans;

    return 0;
}
