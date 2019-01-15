#include <iostream>
using namespace std;
class Card
{
private:
    int card;
    char color;
public:

    Card () {};

    Card(string inpt, char color)
    {
        int num;
        if (inpt[0]>='2' && inpt[0]<='9') num = (int)(inpt[0] - '0');
        else if (inpt[0] == 'J') num = 11;
        else if (inpt[0] == 'Q') num = 12;
        else if (inpt[0] == 'K') num = 13;
        else if (inpt[0] == '1') num = 10;
        else if (inpt[0] == 'A') num = 14;
        else
        {
            if (inpt.size() == 3) num = (int)(inpt[0] - '0') + 10*(int)(inpt[1] - '0');
            else num = (int)(inpt[0] - '0');
        }
        card = num;

        this->color = color;
    }

    void operator = (const Card& value)
    {
        this->card = value.card;
        this->color = value.color;
    }

    Card (const Card& value)
    {
        (*this) = value;
    }

    bool operator == (const Card& value)
    {
        return (card == value.card && color == value.color);
    }

    int getCard () const
    {
        return card;
    }

    char getColor () const
    {
        return color;
    }

    void setCard (const int v)
    {
        card = v;
    }

    void setColor (const char v)
    {
        color = v;
    }



};

ostream& operator << (ostream& OUT, Card& value)
{
    OUT<<value.getCard()<<value.getColor();
    return OUT;
}

istream& operator >> (istream& IN, Card& value)
{
    string inpt;
    IN>>inpt;
    int num;
    if (inpt[0]>='2' && inpt[0]<='9') num = (int)(inpt[0] - '0');
    else if (inpt[0] == 'J') num = 11;
    else if (inpt[0] == 'Q') num = 12;
    else if (inpt[0] == 'K') num = 13;
    else if (inpt[0] == '1') num = 10;
    else num = 14;
    value.setCard(num);
    if (inpt[0] != '1') value.setColor(inpt[1]);
    else value.setColor(inpt[2]);
    return IN;
}


class Hand
{
private:
    Card hand [3];

public:

    Hand () {};
    Hand (Card first, Card second, Card third)
    {
        hand[0] = first;
        hand[1] = second;
        hand[2] = third;
    }

    void operator = (const Hand& value)
    {
        hand[0] = value.hand[0];
        hand[1] = value.hand[1];
        hand[2] = value.hand[2];
    }

    Hand (Hand& value)
    {
        *this = value;
    }

    Card getFirst () const
    {
        return hand[0];
    }

    Card getSecond () const
    {
        return hand[1];
    }

    Card getThird () const
    {
        return hand[2];
    }

    void setCard (Card& value, int pos)
    {
        hand[pos] = value;
    }

    void setAllCards (Card& first, Card& second, Card& third)
    {
        hand[0] = first;
        hand[1] = second;
        hand[2] = third;
    }

    bool straigth () const
    {
        int one = hand[0].getCard();
        int two = hand[1].getCard();
        int three = hand[2].getCard();
        if (one > two)
            if (one > three)
            {
                if (two > three) two--;
                else three--;
                one -= 2;
            }
            else
            {
                three-=2;
                one--;
            }
        else if (two > three)
        {
            if (one > three) one--;
            else three--;
            two-=2;
        }
        else
        {
            three-=2;
            two--;
        }

        return (one == two && two == three);

    }


    bool flush () const
    {
        return (hand[0].getColor() == hand[1].getColor() && hand[1].getColor() == hand[2].getColor());
    }
    bool threeOfAKind () const
    {
        return (hand[0].getCard() == hand[1].getCard() && hand[1].getCard() == hand[2].getCard());
    }
    int twoOfAKind () const
    {
        int ans = 0;
        int one = hand[0].getCard();
        int two = hand[1].getCard();
        int three = hand[2].getCard();

        if (one == two) ans = 1000*one + three;
        else if (two == three) ans = 1000*two + one;
        else if (one == three) ans = 1000*one + two;

        return ans;
    }

    int highestCard() const
    {
        int one = hand[0].getCard();
        int two = hand[1].getCard();
        int three = hand[2].getCard();

        if (one >= two && one >=three) return one;
        if (two >= one && two >= three) return two;
        return three;
    }

    int secondHighestCard() const
    {
        int one = hand[0].getCard();
        int two = hand[1].getCard();
        int three = hand[2].getCard();

        if ((one >= two && one <= three) || (one <= two && one >= three)) return one;
        if ((two >= one && two <= three) || (two <= one && two >= three)) return two;
        return three;

    }

    int worseCard() const
    {
        int one = hand[0].getCard();
        int two = hand[1].getCard();
        int three = hand[2].getCard();

        if (one <= two && one <= three) return one;
        if (two <= one && two <= three) return two;
        return three;

    }

    bool hasCard (Card& value)
    {
        return (value == hand[0] || value == hand[1] || value == hand[2]);
    }
    int power ()
    {
        int ans = 0;

        if (threeOfAKind() && hand[0].getCard() == 3) ans = 9999999;
        else if (straigth() && flush()) ans = 8000000 + highestCard();
        else if (threeOfAKind()) ans = 7000000 + highestCard();
        else if (straigth()) ans = 6000000 + highestCard();
        else if (flush()) ans = 5000000 + highestCard()*10000 + secondHighestCard()*100 + worseCard();
        else if (twoOfAKind() > 0) ans = 4000000 + twoOfAKind();
        else ans = 3000000 + highestCard()*10000 + secondHighestCard()*100 + worseCard();

        return ans;
    }

    bool operator > (Hand& value)
    {
        return (power() > value.power());
    }

    bool operator == (Hand& value)
    {
        return (power() == value.power());
    }

    friend ostream& operator << (ostream& OUT, Hand& value);
    friend istream& operator >> (istream& IN, Hand& value);


};

ostream& operator << (ostream& OUT, Hand& value)
{
    OUT<<value.hand[0]<<" "<<value.hand[1]<<" "<<value.hand[2]<<endl;
    return OUT;
}

istream& operator >> (istream& IN, Hand& value)
{
    IN>>value.hand[0]>>value.hand[1]>>value.hand[2];
    return IN;
}

Hand& bestCombination (Card cards[5], int firstIgnore, int secondIgnore, Hand& dima)
{
    if (firstIgnore == 0 && secondIgnore == 0) return dima;
    if (firstIgnore == secondIgnore) secondIgnore--;

    Hand dummy;
    int j = 0;

    for (int i=0; i<5; i++)
    {
        if (i != firstIgnore && i != secondIgnore)
        {
            dummy.setCard(cards[i], j);
            j++;
        }
    }
    if (dummy > dima) dima = dummy;
    if (secondIgnore == 0)
    {
        secondIgnore = 4;
        firstIgnore--;
    }
    else secondIgnore--;
    //cout<<dima<<endl;
    return bestCombination(cards, firstIgnore, secondIgnore, dima);
}

Hand& bestCombination (Card cards[5], int ignore, Hand& dima)
{
    if (ignore == -1) return dima;
    Hand dummy;
    int j = 0;

    for (int i=0; i<4; i++)
    {
        if (i != ignore)
        {
            dummy.setCard(cards[i], j);
            j++;
        }
    }
    if (dummy > dima) dima = dummy;
    ignore--;
    return bestCombination(cards, ignore, dima);
}

int main()
{
    Hand Sasha;
    Hand Dima;
    cin>>Sasha;
    cin>>Dima;
    Card first, second;
    cin>>first>>second;
    while (!cin.eof())
    {


        Card cards[5];
        Hand dummy1 = Dima;
        Hand dummy2 = Dima;
        cards[0] = Dima.getFirst();
        cards[1] = Dima.getSecond();
        cards[2] = Dima.getThird();
        if (!Dima.hasCard(first) && !Sasha.hasCard(first))
            if (!Dima.hasCard(second) && !Sasha.hasCard(second))
            {
                cards[3] = first;
                Dima = bestCombination(cards, 3, Dima);
                cards[4] = second;
                if (!(first == second))Dima = bestCombination(cards, 3, 4, Dima);
                cards[3] = second;
                Dima = bestCombination(cards, 3, Dima);

            }
            else
            {
                cards[3] = first;
                Dima = bestCombination(cards, 3, Dima);
            }
        else if (!Dima.hasCard(second) && !Sasha.hasCard(second))
        {
            cards[3] = second;
            Dima = bestCombination(cards, 3, Dima);
        }
        if (Dima > Sasha) cout<<"Dima";
        else if (Sasha > Dima) cout<<"Sasha";
        else cout<<"Artyom";
        cout<<endl;
        cin>>Sasha;
        cin>>Dima;
        cin>>first>>second;
    }



    return 0;
}
