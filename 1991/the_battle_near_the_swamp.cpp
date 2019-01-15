#include <iostream>
using namespace std;
int main()
{
    int n, k, unused = 0, survived = 0, input;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input <= k)
            survived += k - input;
        else
            unused += input - k;
    }

    cout << unused << " " << survived;
    return 0;
}
