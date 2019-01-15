#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int ID[n], M[n], max = -1;
    bool hasThisNumber[102];
    for (int i = 0; i <= 101; i++)
        hasThisNumber[i] = false;
    for (int i = 0; i < n; i++) {
        cin >> ID[i] >> M[i];
        if (max < M[i])
            max = M[i];
        hasThisNumber[M[i]] = true;
    }
    for (int i = max; i >= 0; i--)
        if (hasThisNumber[i] == true)
            for (int j = 0; j < n; j++) {
                if (M[j] == i)
                    cout << ID[j] << " " << M[j] << endl;
            }

    return 0;
}
