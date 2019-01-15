#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i];
}

bool wordIsOk(int arr[], int n)
{
    int br = 0;

    for (int i = 0; i < n; i++) {
        br += arr[i] * (i + 1);
    }
    if (br % (n + 1) == 0)
        return true;
    else
        return false;
}

bool insertNumber(int* arr, int pos, int number, int n)
{
    int newarr[n];
    for (int i = 0; i <= n; i++) {
        if (i < pos)
            newarr[i] = arr[i];
        else if (i == pos)
            newarr[i] = number;
        else
            newarr[i] = arr[i - 1];
    }
    if (wordIsOk(newarr, n)) {
        print(newarr, n);
        return true;
    }
    else
        return false;
}

bool removeNumber(int* arr, int pos, int n)
{
    int newarr[n - 1];
    for (int i = 0; i < n; i++) {
        if (i < pos)
            newarr[i] = arr[i];
        else if (i > pos)
            newarr[i - 1] = arr[i];
    }
    if (wordIsOk(newarr, n - 1)) {
        print(newarr, n - 1);
        return true;
    }
    else
        return false;
}

void firstCase(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            arr[i] = 0;
            if (wordIsOk(arr, n)) {
                print(arr, n);
                break;
            }
            else
                arr[i] = 1;
        }
    }
}

void secondCase(int arr[], int n)
{
    int i = 0;
    while (i < n + 1 && !insertNumber(arr, i, 0, n + 1) && !insertNumber(arr, i, 1, n + 1))
        i++;
}

void thirdCase(int arr[], int n)
{
    int i = 0;
    while (i < n && !removeNumber(arr, i, n))
        i++;
}

int main()
{
    int n;
    cin >> n;
    string input;
    cin.ignore();
    getline(cin, input);

    while (!cin.eof()) {

        int j = 0;
        int arr[n + 1];
        for (int i = 0; i < input.length(); i++) {

            if (input[i] != ' ') {
                arr[j] = (int)(input[i] - '0');
                j++;
            }
        }
        if (j == n && wordIsOk(arr, j))
            print(arr, j);
        else if (j == n)
            firstCase(arr, j);
        else if (j == n - 1)
            secondCase(arr, j);
        else
            thirdCase(arr, j);
        cout << endl;
        getline(cin, input);
    }

    return 0;
}
