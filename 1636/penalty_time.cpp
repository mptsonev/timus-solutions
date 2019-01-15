#include <iostream>
using namespace std;
int main()
{
    int n, k, input, total_time = 0;
    cin >> n >> k;
    for (int i = 0; i < 10; i++) {
        cin >> input;
        total_time += input * 20;
    }
    if (k - total_time >= n)
        cout << "No chance.";
    else
        cout << "Dirty debug :(";
    return 0;
}
