#include <iostream>
#include <map>
using namespace std;
int main()

{
    map<string, int> a;
    int n;
    cin >> n;
    string c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a[c]++;
        if (a[c] == 2)
            cout << c << endl;
    }

    return 0;
}
