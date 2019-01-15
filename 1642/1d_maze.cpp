#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < tmp)
            i++;
        while (arr[j] > tmp)
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
    int n, x;
    cin >> n >> x;
    int napred, nazad;
    int obstacles[n];
    for (int i = 0; i < n; i++) {
        cin >> obstacles[i];
    }
    quickSort(obstacles, 0, n - 1);
    if (x == 0)
        cout << 0 << " " << 0;
    else if (x < 0) {
        int i = 0;
        while (obstacles[i] < x && i < n)
            i++;
        if (obstacles[i] > 0) {
            nazad = (-1) * x;
            napred = (-1) * x + 2 * obstacles[i];
            cout << napred << " " << nazad;
        }
        else
            cout << "Impossible";
    }

    else {
        int i = 0;
        while (obstacles[i] < x && i < n) {
            i++;
            if (obstacles[i - 1] < 0 && obstacles[i] > 0)
                nazad = obstacles[i - 1];
        }

        if (obstacles[i - 1] > 0 && obstacles[i - 1] < x)
            cout << "Impossible";
        else {
            napred = x;
            nazad = (-2) * nazad + napred;
            cout << napred << " " << nazad;
        }
    }

    return 0;
}
