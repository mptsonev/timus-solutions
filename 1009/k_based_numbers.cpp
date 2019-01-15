#include <iostream>
using namespace std;

int recurs(int n, int k)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return k - 1;
    else
        return (k - 1) * (recurs(n - 1, k) + recurs(n - 2, k));
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << recurs(N, K);

    return 0;
}