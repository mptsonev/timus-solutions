#include <iostream>
#include <map>
using namespace std;

int maxOfThree(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    if (c >= a && c >= b)
        return c;
}
int main()
{
    string inputs;
    int n;
    string one = "Macaroni Penguin";
    string two = "Little Penguin";
    string three = "Emperor Penguin";
    map<string, int> a;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {

        getline(cin, inputs);
        a[inputs]++;
    }
    if (a[one] >= a[two] && a[one] >= a[three])
        cout << one;
    else if (a[two] >= a[one] && a[two] >= a[three])
        cout << two;
    else if (a[three] >= a[one] && a[three] >= a[two])
        cout << three;

    return 0;
}
