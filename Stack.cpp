#include"iostream"
#include"stdlib.h"

using namespace std;

class STACK
{
private:
    #define SIZE 4
    int a[SIZE],top;
public:
    STACK()
    {
        top=-1;
    }

    STACK operator+(int element)
    {
        // S1 = S1+ELEMENT

        if(this->top==SIZE-1)
            {

            cout<<"Stack is full!\n";
            return (*this);
             }
      a[++top]=element;
        return *this;
    }

    STACK operator--(int)
    {
        if(this->top==-1)
        {
            cout<<"\nStack is empty\n";
            return *this;
        }
        cout<<"\nDeleted element is "<<a[top--];
        return *this;
    }

    friend ostream& operator<<(ostream &x, const STACK &y);

};
    ostream& operator<<(ostream &x, const STACK &y)
    {
        if(y.top==-1)
        {
            x<<"\nStack is empty!!";
            return x;
        }

        for(int i=y.top;i>=0;i--)
        {
            x<<"\n"<<y.a[i]<<"\n";
        }
        return x;
    }

    int main()
    {
        STACK s1;
        int element, ch;
        for(;;)
        {
            cout<<"\n\nEnter 1 to push 2 to pop 3 to exit\n";
            cin>>ch;
            switch(ch)
            {
                case 1: cout<<"Enter the element \n";
                        cin>>element;
                        s1=s1+element;
                        cout<<s1;
                        break;
                case 2: s1=s1--;
                        cout<<s1;
                        break;
                case 3: exit(0);
            }
        }
        return 0;
    }
