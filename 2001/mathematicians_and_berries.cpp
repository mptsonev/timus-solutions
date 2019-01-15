#include <iostream>
using namespace std;
int main()

{
    int a1, b1;
    cin >> a1 >> b1;
    int first_mass = a1;
    int second_mass = b1;
    cin >> a1 >> b1;
    second_mass -= b1;
    cin >> a1 >> b1;
    first_mass -= a1;
    cout << first_mass << " " << second_mass;

    return 0;
}
