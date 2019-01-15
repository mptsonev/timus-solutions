#include <iostream>
#include <map>
using namespace std;

struct experiment {
    int number;
    string condition;
};

int main()
{
    int n;
    cin >> n;
    experiment data[n];
    for (int i = 0; i < n; i++)
        cin >> data[i].number >> data[i].condition;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            if (data[i].number > data[j].number) {
                swap(data[i].number, data[j].number);
                swap(data[i].condition, data[j].condition);
            }
    }

    int counter = 0;
    while (data[counter].condition == "hungry")
        counter++;
    for (int i = counter + 1; i < n; i++)
        if (data[i].condition == "hungry") {
            cout << "Inconsistent";
            return 0;
        }
    if (counter == n || n == 0)
        cout << 10;
    else
        cout << data[counter].number;

    return 0;
}