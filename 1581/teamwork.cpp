#include <iostream>
using namespace std;

int main()
{
    int n, k, counter = 0, prev;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (i == 0)
            prev = k;
        if (k == prev)
            counter++;
        else {
            cout << counter << " " << prev << " ";
            prev = k;
            counter = 1;
        }
    }

    cout << counter << " " << k;

    return 0;
}
