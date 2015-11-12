#include"iostream"
#include"stdlib.h"
#include"string.h"
using namespace std;

class String
{
 private:
        char str[20];
 public:
        String operator+(const String y)const
        {
             static String temp =" ";
            strcpy(temp.str,this->str);
            strcat(temp.str,y.str);
            return temp;
        }

        String (char str[])
        {
            strcpy(this->str,str);

        }
        String(const String &x)
        {
            strcpy(this->str,x.str);

        }

        friend ostream& operator<<(ostream &, const String z);

};

ostream& operator<<(ostream &x, const String z)
{
    x<<z.str;
    return x;

}


int main()
{
    String s1="VTU";
    String s2="Belgaum";

    cout<<s1<<endl;
    cout<<s2<<endl;
    String s3= s1+s2;
    cout<<s3;

    return 0;
}
