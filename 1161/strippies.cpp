#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void quickSort(double arr[], int left, int right)
{
    int i = left, j = right;
    double tmp = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] > tmp)
            i++;
        while (arr[j] < tmp)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main()
{
    int n;
    cin >> n;
    double arr[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n);
    double curr = arr[0];
    for (int i = 1; i < n; i++) {
        double x = (arr[i]);
        curr = 2 * sqrt(x * curr);
    }
    cout << setprecision(2) << fixed << curr;

    return 0;
}
