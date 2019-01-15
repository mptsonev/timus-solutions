#include <iostream>
using namespace std;
int main()
{
    int current_me, current_taxi, me_up, taxi_down;
    cin >> current_me >> me_up >> current_taxi >> taxi_down;
    while (current_me <= current_taxi) {
        current_me += me_up;
        if (current_me > current_taxi)
            current_me = current_taxi;
        current_taxi -= taxi_down;
    }

    cout << current_me;
    return 0;
}
