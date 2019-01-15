#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int voters[k];
    for (int i = 0; i < k; i++)
        cin >> voters[i];
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++)
            if (voters[i] > voters[j])
                swap(voters[i], voters[j]);
    }
    int ans = 0;
    for (int i = 0; i < k / 2 + 1; i++)
        ans += voters[i] / 2 + 1;
    cout << ans;
    return 0;
}