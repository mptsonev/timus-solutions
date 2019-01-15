#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int lines = m * n - 1;
    if (lines % 2 == 1)
        cout << "[:=[first]";
    else
        cout << "[second]=:]";
    return 0;
}
