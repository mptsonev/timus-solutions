#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int x)
{
    if (x == 1 || x == 0)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

void setArray(int arr[], int primeNumbersCount)
{
    int count = 2, primeCounter = 0;
    while (primeCounter <= primeNumbersCount) {
        while (!isPrime(count))
            count++;
        arr[primeCounter] = count;
        //cout<<arr[primeCounter]<<endl;
        primeCounter++;
        count++;
    }
}

int main()

{
    int n;
    cin >> n;
    int input[n];
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        max = max > input[i] ? max : input[i];
    }
    int primeNumberList[max + 1];
    setArray(primeNumberList, max);
    for (int i = 0; i < n; i++)
        cout << primeNumberList[input[i] - 1] << endl;

    return 0;
}
