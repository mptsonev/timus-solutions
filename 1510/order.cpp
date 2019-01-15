#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, input, counter = 0, curr;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (counter == 0) {
            curr = input;
            counter = 1;
        }
        else if (curr != input)
            counter--;
        else
            counter++;
    }
    cout << curr;

    return 0;
}