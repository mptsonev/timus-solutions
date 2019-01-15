#include <iostream>
using namespace std;

class Pair {
private:
    int x;
    int y;

public:
    Pair(int _x, int _y)
        : x(_x)
        , y(_y){};
    int getX() const
    {
        return x;
    }

    Pair()
    {
        x = -1;
        y = -1;
    }

    int getY() const
    {
        return y;
    }

    void setX(const int _x)
    {
        x = _x;
    }

    void setY(const int _y)
    {
        y = _y;
    }

    void rotateBy90degrees()
    {
        int y1 = y;
        y = x;
        x = 4 - y1 - 1;
    }
    void print() const
    {
        cout << x << " " << y << endl;
    }

    bool compare(const Pair value)
    {

        if (y < value.getY() || (y == value.getY() && x < value.getX()))
            return true;
        return false;
    }
};

void swapValues(Pair& value1, Pair& value2)
{
    Pair dummy(value1.getX(), value1.getY());
    value1.setX(value2.getX());
    value1.setY(value2.getY());
    value2.setX(dummy.getX());
    value2.setY(dummy.getY());
}

void sortPairs(Pair values[])

{

    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++)
            if (values[j].compare(values[i]))
                swapValues(values[i], values[j]);
    }
}

int main()
{
    Pair pairs[4];
    string input;
    int pair_count = 0;
    for (int i = 0; i < 4; i++) {
        cin >> input;
        for (int j = 0; j < 4; j++) {
            if (input[j] == 'X') {
                pairs[pair_count].setX(j);
                pairs[pair_count].setY(i);
                pair_count++;
            }
        }
    }
    string password[4];
    for (int i = 0; i < 4; i++) {
        cin >> password[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << password[pairs[j].getY()][pairs[j].getX()];
        for (int k = 0; k < 4; k++)
            pairs[k].rotateBy90degrees();
        sortPairs(pairs);
    }

    return 0;
}
