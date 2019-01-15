#include <iostream>
#include <cmath>
using namespace std;
bool isLucky(int values[], int digits)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < digits / 2; i++) {
        sum1 += values[i];
        sum2 += values[digits - i - 1];
    }
    return sum1 == sum2;
}
void nextPerm(int values[], int n)
{
    int i = n - 1;
    while (values[i] == 9) {
        values[i] = 0;
        i--;
    }
    values[i]++;
}
int main()
{
    int tickets_count = 1;
    int n;
    cin >> n;
    int diapason = 1, arr[n];
    for (int i = 0; i < n; i++) {
        diapason *= 10;
        arr[i] = 0;
    }

    for (int i = diapason / 10; i < diapason + diapason / 10 - 1; i++) {
        if (isLucky(arr, n))
            tickets_count++;
        nextPerm(arr, n);
    }

    cout << tickets_count;

    return 0;
}
