#include <iostream>
#include <string.h>
using namespace std;
int inputCount[3];
int main()
{
    int n;
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        inputCount[input - 1]++;
    }
    int br = 0, br2 = 0;
    if (n < 3)
        cout << "No";
    else if (n >= 3 && n <= 5) {
        for (int i = 0; i < 3; i++) {
            if (inputCount[i] >= 2)
                br++;
            if (inputCount[i] >= 1)
                br2++;
        }
        if (br == 2 || br2 == 3)
            cout << "Yes";
        else
            cout << "No";
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (inputCount[i] != 0)
                br++;
        }
        if (br > 1)
            cout << "Yes";
        else
            cout << "No";
    }

    return 0;
}
