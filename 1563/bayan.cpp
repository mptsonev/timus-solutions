#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main()
{
    int n, ans = 0;
    string str;
    cin >> n;
    cin.ignore();
    map<string, int> a;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        a[str]++;
        if (a[str] > 1)
            ans++;
    }
    cout << ans;

    return 0;
}
