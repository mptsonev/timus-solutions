#include <iostream>
using namespace std;
const int fromUpperToLowerAdd = 'a' - 'A';
int main()
{
    char input;
    bool shouldBeUpper = true;

    while (cin.get(input)) {
        if (shouldBeUpper && input >= 'A' && input <= 'Z') {
            shouldBeUpper = false;
            cout << input;
        }
        else if (input >= 'A' && input <= 'Z')
            cout << (char)(input + fromUpperToLowerAdd);
        else
            cout << input;
        if (input == '.' || input == '!' || input == '?')
            shouldBeUpper = true;
    }

    return 0;
}