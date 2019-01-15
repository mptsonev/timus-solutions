#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a = (long long)n * (n + 1) / 2 * (n + 2);
    cout << a;

    return 0;
}
