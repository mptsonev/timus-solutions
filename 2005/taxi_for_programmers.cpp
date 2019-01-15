#include <iostream>
using namespace std;

int main()
{
    int table[5][5], sequence[5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> table[i][j];
    int sum = table[0][1] + table[1][2] + table[2][3] + table[3][4];
    int minimal = sum;
    for (int i = 0; i < 5; i++)
        sequence[i] = i + 1;
    sum = table[0][3] + table[3][2] + table[2][1] + table[1][4];
    if (minimal > sum) {
        minimal = sum;
        sequence[1] = 4;
        sequence[2] = 3;
        sequence[3] = 2;
    }
    sum = table[0][2] + table[2][1] + table[1][3] + table[3][4];
    if (minimal > sum) {
        minimal = sum;
        sequence[1] = 3;
        sequence[2] = 2;
        sequence[3] = 4;
    }
    sum = table[0][2] + table[2][3] + table[3][1] + table[1][4];
    if (minimal > sum) {
        minimal = sum;
        sequence[1] = 3;
        sequence[2] = 4;
        sequence[3] = 2;
    }
    cout << minimal << endl;
    for (int i = 0; i < 5; i++)
        cout << sequence[i] << " ";

    return 0;
}
