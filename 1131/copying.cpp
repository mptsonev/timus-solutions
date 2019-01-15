#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    int n, k, time = 0;
    cin >> n >> k;
    n--;
    int power = 1;

    while (n > 0) {
        if (power <= k) {
            n -= power;
            power *= 2;
            time++;
        }
        else {
            time += n / k;
            if (n % k != 0)
                time++;
            n = 0;
        }
    }
    cout << time;

    return 0;
}
