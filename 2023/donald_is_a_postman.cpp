#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int stepsCount = 0;
    int currentStep = 1, toGo;
    string inpit;
    for (int i = 0; i < n; i++) {
        cin >> inpit;
        if (inpit[0] == 'A' || inpit[0] == 'P' || inpit[0] == 'O' || inpit[0] == 'R')
            toGo = 1;
        else if (inpit[0] == 'B' || inpit[0] == 'M' || inpit[0] == 'S')
            toGo = 2;
        else
            toGo = 3;
        stepsCount += abs(currentStep - toGo);
        currentStep = toGo;
    }
    cout << stepsCount;
    return 0;
}
