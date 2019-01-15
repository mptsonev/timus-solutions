#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp = arr[(left + right) / 2];

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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}