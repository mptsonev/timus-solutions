#include <iostream>
#include <cstring>
using namespace std;

struct seat {
    unsigned short int number;
    char seat;
};

seat& split(char* input)
{
    int num = 0;
    seat ans;
    ans.seat = input[strlen(input) - 1];
    for (int i = 0; i < strlen(input) - 1; i++) {
        num += input[i] - 48;
        num *= 10;
    }
    num /= 10;
    ans.number = num;
    return ans;
}

bool window(seat value)
{
    bool ans = false;
    if (value.seat >= 97)
        value.seat -= 32;
    if (value.seat == 'A' || value.seat == 'K')
        ans = true;
    else if (value.number < 3 && value.seat == 'D')
        ans = true;
    else if (value.number >= 3 && value.number <= 20 && value.seat == 'F')
        ans = true;

    return ans;
}

bool aisle(seat value)
{
    bool ans = false;
    if (value.seat >= 97)
        value.seat -= 32;

    if (value.number <= 20 && value.seat >= 'A' && value.seat <= 'F')
        ans = true;
    else if (value.seat == 'C' || value.seat == 'D' || value.seat == 'G' || value.seat == 'H')
        ans = true;
    return ans;
}

int main()
{
    char input[5];
    int n;
    char c;
    seat test;
    cin >> n >> c;
    test.number = n;
    test.seat = c;

    if (window(test))
        cout << "window";
    else if (aisle(test))
        cout << "aisle";
    else
        cout << "neither";

    return 0;
}
