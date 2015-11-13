#include"iostream"
#include"math.h"

using namespace std;

class octal
{
    int octnum;
public:
    octal(int x);
    int operator+(int k);
    friend ostream& operator<<(ostream &x, octal &y);
};

octal::octal(int x)
{
    int res=0,rem,i=0;
    while(x)
    {
        rem=x%8;
        res+=rem*pow(10.0,i);
        x=x/8;
        i++;
    }
    octnum=int(res);
}

int octal::operator+(int k)
{
    int temp=octnum;
    int rem=0,res=0,i=0;
    while(temp)
    {
        rem=temp%10;
        res+=rem*pow(8.0,i);
        temp=temp/10;i++;
    }
    return (int)(res+k);
}

ostream& operator<<(ostream &x, octal &y)
{
    x<<y.octnum;
    return x;
}

int main()
{
int x,k;
cout<<"Enter the element\n";
cin>>x;
octal h=x;
cout<<"Octal equivalentis \n:"<<h<<endl;
cout<<"Enter value for k\n";
cin>>k;
int y=h+k;
cout<<"Value of y is:"<<y<<endl;
return 0;
}
