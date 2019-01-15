#include <iostream>
using namespace std;

int getIndex(char a)
{
    return a - 97;
}

char getChar(int a)
{
    return (char)(a + 97);
}

void translate(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        while (a[i] < a[i - 1])
            a[i] += 26;
    }

    for (int i = n - 1; i > 0; i--)
        a[i] -= a[i - 1];
    if (a[0] - 5 < 0)
        a[0] += 21;
    else
        a[0] -= 5;
}

int main()
{
    string input;
    cin >> input;
    int codes[input.length()];
    for (int i = 0; i < input.length(); i++)
        codes[i] = getIndex(input[i]);
    translate(codes, input.length());
    for (int i = 0; i < input.length(); i++)
        cout << getChar(codes[i]);

    return 0;
}