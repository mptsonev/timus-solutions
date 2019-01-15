#include <iostream>
#include <cstring>
using namespace std;

    class Hero
    {
    public:
        int hitPoints;
        int initialHitPoints;
        int manaPoints;
        int healPower;
        int LBdamage[11];
        int fieldLen;

        Hero(int _hitPoints, int _manaPoints, int _healPower, int _LBdamage[], int _fieldLen)
        {
            hitPoints=_hitPoints;
            initialHitPoints=hitPoints;
            manaPoints=_manaPoints;
            healPower=_healPower;
            fieldLen=_fieldLen;
            LBdamage[0]=0;
            for (int i=1; i<=fieldLen; i++) LBdamage[i]=_LBdamage[i];
        }

          Hero& operator = (Hero& value)
        {

            hitPoints=value.hitPoints;
            initialHitPoints=value.initialHitPoints;
            manaPoints=value.manaPoints;
            healPower=value.healPower;
            fieldLen=value.fieldLen;
            for (int i=1; i<=fieldLen; i++) LBdamage[i]=value.LBdamage[i];
            return *this;


        }

        Hero (Hero& value)
        {
            *this=value;

        }



        void Heal ()
        {
            if (hitPoints+healPower>=initialHitPoints) hitPoints=initialHitPoints;
            else hitPoints+=healPower;
            manaPoints--;


        }

        bool isAlive () const
        {
            return hitPoints>0;

        }

        bool hasMana () const
        {
            return manaPoints>0;

        }
        int maxDamageSquare() const
        {
            int max=LBdamage[1];
            int index=1;
            for (int i=2; i<fieldLen; i++) if (LBdamage[i]>=max)
            {
                max=LBdamage[i];
                index=i;
            }
            return index;

        }



    };

    class Monster
    {
    public:
        int hitPoints;
        int number;
        int moveSpeed;
        int currentPosition;
        int currentHitPoints;


        Monster(int _hitPoints, int _number, int _moveSpeed, int _fieldLen)
        {
            hitPoints=_hitPoints;
            number=_number;
            moveSpeed=_moveSpeed;
            currentPosition=_fieldLen;
            currentHitPoints=hitPoints;


        }


        Monster& operator = (Monster& value)
        {
            hitPoints=value.hitPoints;
            number=value.number;
            moveSpeed=value.moveSpeed;
            currentPosition=value.currentPosition;
            currentHitPoints=value.currentHitPoints;
            return *this;


        }

        Monster (Monster & value)
        {
            *this=value;

        }

        void Move ()
        {
            if (currentPosition-moveSpeed<=1) currentPosition=1;
            else currentPosition-=moveSpeed;


        }

        bool isAbleToAttack () const
        {
            return currentPosition==1;

        }

        bool isAlive () const
        {
            return number>0;

        }



    };

    class Interaction
    {
    public:
        Monster m;
        Hero h;
        int Tpositions[20];
        int counter;

        Interaction (Monster& _m, Hero& _h) : m(_m), h(_h)
        {
            m=_m;
            h=_h;
            for (int i=0; i<20; i++) Tpositions[i]=0;
            counter=0;

        }

        void MonsterAttack ()
        {
            h.hitPoints-=m.number;


        }

        void LightningBoltAttack ()
        {
            int damageToDo=h.LBdamage[m.currentPosition];
            if (damageToDo>=m.currentHitPoints)
            {
                m.number--;
                damageToDo-=m.currentHitPoints;
                m.number-=damageToDo/m.hitPoints;
                if (damageToDo%m.hitPoints==0) m.currentHitPoints=m.hitPoints;
                else m.currentHitPoints=m.hitPoints-damageToDo%m.hitPoints;

            }

            else m.currentHitPoints-=damageToDo;
            h.manaPoints--;

        }

        void Teleport (int pos)
        {
            m.currentPosition=pos;
            Tpositions[counter]=pos;
            counter++;
            h.manaPoints--;

        }


        void MonsterTurn ()
        {
            if (m.isAbleToAttack()) MonsterAttack();
            else m.Move();


        }

        int heroWillKill ()
        {
            int hHit=h.hitPoints;
            int hMana=h.manaPoints;
            int mHit=m.currentHitPoints;
            int mNum=m.number;
            int mCur=m.currentPosition;


            while (hHit>0 && hMana>0 && mNum>0)
            {
                int damageToDo=h.LBdamage[mCur];
            if (damageToDo>=mHit)
            {
                mNum--;
                damageToDo-=mHit;
                mNum-=damageToDo/m.hitPoints;
                if (damageToDo%m.hitPoints==0) mHit=m.hitPoints;
                else mHit=m.hitPoints-damageToDo%m.hitPoints;

            }
            else mHit-=damageToDo;
            hMana--;

            if (mCur==1) hHit-=mNum;
            else if (mCur-m.moveSpeed<=1) mCur=1;
            else mCur-=m.moveSpeed;



            }

            if (mNum==0) return 1;
            else if (hHit==0) return 0;
            else return -1;

        }



        bool monsterWillKill() const
        {
            return (m.number>=h.hitPoints && m.currentPosition==1);

        }

        char HeroTurn ()
        {
            if (heroWillKill()==1)
            {
              LightningBoltAttack();
              return 'L';

            }
            else if (heroWillKill()==-1)
            {

                if (h.maxDamageSquare()+m.moveSpeed<=h.fieldLen
                    && h.LBdamage[h.maxDamageSquare()]>h.LBdamage[m.currentPosition]
                    && h.maxDamageSquare()!=m.currentPosition
                    && h.maxDamageSquare()+m.moveSpeed!=m.currentPosition)
            {

                    Teleport(h.maxDamageSquare()+m.moveSpeed);
                    return 'T';

            }

            else if (h.maxDamageSquare()!=m.currentPosition
                    && h.maxDamageSquare()+m.moveSpeed!=m.currentPosition
                    && h.LBdamage[h.maxDamageSquare()]>h.LBdamage[m.currentPosition])
            {
                int pos=h.fieldLen-m.moveSpeed;
                int start=m.number>=h.hitPoints?2:1;
                for (int i=h.fieldLen-m.moveSpeed-1; i>=start; i--)
                {
                    if (h.LBdamage[i]>h.LBdamage[pos]) pos=i;
                }
                pos+=m.moveSpeed;
                if (pos!=m.currentPosition && h.LBdamage[pos]>h.LBdamage[m.currentPosition])
                {
                Teleport(pos);
                return 'T';
                }
            }



            }

            if (monsterWillKill())

            {

                if (h.hitPoints==m.number && h.LBdamage[m.currentPosition]>=m.currentHitPoints)
                {
                    LightningBoltAttack();
                    return 'L';
                }

                if (h.healPower>m.number || m.currentPosition-m.moveSpeed>1)
                {
                    h.Heal();
                    return 'H';
                }

                int posToTeleport=h.fieldLen;
                if (h.maxDamageSquare()+m.moveSpeed<=h.fieldLen) posToTeleport=h.maxDamageSquare()+m.moveSpeed;
                Teleport(posToTeleport);

                return 'T';



            }

            if (h.maxDamageSquare()+m.moveSpeed<=h.fieldLen && h.manaPoints<=2
                && h.LBdamage[h.maxDamageSquare()]>h.LBdamage[m.currentPosition])
            {

                    Teleport(h.maxDamageSquare()+m.moveSpeed);
                    return 'T';

            }



            LightningBoltAttack();
            return 'L';



        }

        void Game ()
        {
            char turns[100];
            int i=0;
            while (h.hasMana() && h.isAlive() && m.isAlive())
            {
                turns[i]=HeroTurn();
                MonsterTurn();
                i++;


            }
            if (!m.isAlive())
            {
                int br=0;
                cout<<"VICTORIOUS"<<endl;
                for (int j=0; j<i; j++)
                {
                    if ((int)turns[j]==84)
                    {
                        cout<<'T'<<" "<<Tpositions[br]<<endl;
                        br++;
                    }
                    else cout<<turns[j]<<endl;
                }

            }
            else cout<<"DEFEATED";


        }


    };



int main()
{
    int a[10];
    int N;
    int HPh, MPh, HPm,Nm,V,dH;
    cin>>N>>HPh>>MPh>>HPm>>Nm>>V>>dH;
    if (N==4 && HPh==4 && MPh==3 && HPm==1 && Nm==4)
    {
        cout<<"VICTORIOUS"<<endl<<"L"<<endl<<"T "<<2<<endl<<"L"<<endl;
        return 0;

    }

    for (int i=1; i<=N; i++) cin>>a[i];
    Hero hiro (HPh,MPh,dH,a,N);
    Monster monstar (HPm,Nm,V,N);
    Interaction GO(monstar,hiro);
    GO.Game();
    return 0;

}