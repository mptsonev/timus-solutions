#include <iostream>
#include <cstring>
using namespace std;
int string_to_int(string a)
{
    int length = a.length();
    int ans = 0;
    short int i = 0;
    while (a[i] == '0')
        i++;
    while (i < length) {

        ans += a[i] - 48;
        ans *= 10;
        i++;
    }
    return ans / 10;
}
int main()
{

    string inputs;
    cin >> inputs;
    int first_combination = string_to_int(inputs);
    cin >> inputs;
    int second_combination = string_to_int(inputs);
    if (first_combination % 2 == 0 || second_combination % 2 == 1)
        cout << "yes";
    else
        cout << "no";

    return 0;
}