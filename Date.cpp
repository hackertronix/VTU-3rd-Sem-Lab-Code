#include"iostream"
using namespace std;

int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

class date
{
    int d,m,y;
public:
    date():d(0),m(0),y(0){}
    void accept()
    {
        cin>>d>>m>>y;

    }

    int operator-(const date &x)const
    {
        int count=0;
        date t=x;
        while(t.d!=d||t.m!=m||t.y!=y)
        {
            t.d+=1;
            count++;
            if(t.d>mon[t.m])
            {
                t.d=1;
                t.m+=1;
                if(t.m>12)
                {
                    t.m=1;
                    t.y+=1;
                }
            }
        }
        return count;
    }

    date operator+(const int &x)const
    {
        date t=*this;
        int nod=x;
        while(nod>0)
        {
            t.d+=1;
            nod--;
            if(t.d>mon[t.m])
            {
                t.d=1;
                t.m+=1;
                if(t.m>12)
                {
                    t.m=1;
                    t.y+=1;
                }
            }

        }
        return t;
    }

    friend ostream& operator<<(ostream&, const date &);
};

ostream& operator<<(ostream &x, const date &y)
{
    x<<y.d<<y.m<<y.y;
    return x;
}

int main()
{
    date d1,d2,d3;
    d1.accept();
    cout<<d1;
    d2.accept();
    cout<<d2;
    int nod=d1-d2;
    cout<<"No of days= "<<nod<<"\n";
    d3=d2+nod;
    cout<<d3;
}
