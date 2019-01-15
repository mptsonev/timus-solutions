#include <iostream>
using namespace std;
int horizontal = 1, vertical = 0, turns = 0;
class Pair {
private:
    int x, y;

public:
    Pair(int _x = 0, int _y = 0)
        : x(_x)
        , y(_y){};
    const Pair& operator=(const Pair& value)
    {
        this->x = value.x;
        this->y = value.y;
    }

    Pair(const Pair& value)
    {
        *this = value;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    bool operator==(const Pair& value)
    {
        if (this->x == value.x && this->y == value.y)
            return true;
        return false;
    }

    bool operator!=(const Pair& value)
    {
        return !(*this == value);
    }

    void print() const
    {
        cout << x << " " << y << endl;
    }

    void Move()
    {
        x += vertical;
        y += horizontal;
    }
    friend istream& operator>>(istream&, Pair&);
};

void printMap(int* a[], int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void changeDirection()
{
    if (horizontal == 1 && vertical == 0) {
        horizontal = 0;
        vertical = 1;
    }
    else if (horizontal == 0 && vertical == 1) {
        horizontal = -1;
        vertical = 0;
    }
    else if (horizontal == -1 && vertical == 0) {
        horizontal = 0;
        vertical = -1;
    }
    else if (horizontal == 0 && vertical == -1) {
        horizontal = 1;
        vertical = 0;
    }
}
istream& operator>>(istream& IN, Pair& value)
{
    IN >> value.x >> value.y;
    return IN;
}

int findFirst(Pair& one, Pair& two, int n, int m, int* a[])
{
    Pair dummy(1, 1);
    while (dummy != one && dummy != two) {

        a[dummy.getX()][dummy.getY()] = 0;
        if (a[dummy.getX() + vertical][dummy.getY() + horizontal] == 0)
            changeDirection();

        dummy.Move();
    }
    if (dummy == one)
        return 1;
    else
        return 2;
}

void findSecond(Pair& one, Pair& two, int n, int m, int* a[])
{
    Pair dummy(one);
    while (dummy != two) {
        a[dummy.getX()][dummy.getY()] = 0;
        if (a[dummy.getX() + vertical][dummy.getY() + horizontal] == 0)
            changeDirection();

        dummy.Move();
        turns++;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int* gravesMap[n + 2];
    for (int i = 0; i < n + 2; i++)
        gravesMap[i] = new int[m + 2];
    for (int i = 0; i <= m + 1; i++) {
        gravesMap[0][i] = 0;
        gravesMap[n + 1][i] = 0;
    }

    for (int i = 0; i <= n + 1; i++) {
        gravesMap[i][0] = 0;
        gravesMap[i][m + 1] = 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            gravesMap[i][j] = 1;

    Pair firstTreasure, secondTreasure;
    cin >> firstTreasure >> secondTreasure;
    if (findFirst(firstTreasure, secondTreasure, n + 2, m + 2, gravesMap) == 1)
        findSecond(firstTreasure, secondTreasure, n + 2, m + 2, gravesMap);
    else
        findSecond(secondTreasure, firstTreasure, n + 2, m + 2, gravesMap);

    cout << turns;

    return 0;
}