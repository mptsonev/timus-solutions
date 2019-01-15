#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, string> ans;
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    char letter;
    cin >> letter;
    for (int i = 0; i < n; i++)
        if (ans[i][0] == letter)
            cout << ans[i] << endl;
}
