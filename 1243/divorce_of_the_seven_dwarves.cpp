#include <iostream>
#include <cstring>
using namespace std;

void convert(string b, int a[])
{

    for (int i = 0; i < b.length(); i++) {
        a[i] = b[i] - '0';
    }
}

int divisible(int a[], int n)
{
    int rem = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr < 7) {
            curr *= 10;
            curr += a[i];
        }
        if (curr >= 7) {
            curr = curr % 7;
        }
    }
    return curr;
}

int main()

{
    int a[100];
    string input;
    cin >> input;
    convert(input, a);
    cout << divisible(a, input.length());

    return 0;
}
