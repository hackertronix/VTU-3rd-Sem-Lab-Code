#include "iostream"
#include"stdlib.h"
using namespace std;

class list
{
    struct node
    {
        int data;
        node *link;
        /*ALTERNATE WAY

        node()
        {
            cout<<"Enter the element\n";
            cin>>data;
            link=NULL;
        }*/
    };

    node *first;
public:
    list():first(NULL){}
    void insertFront();
    void deleteFront();
    void display();
};

void list::insertFront()
{
    node *temp=new node;
    int ele;
    cout<<"\nEnter element\n";
    cin>>ele;
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        first=temp;
        return;
    }

    temp->link=first;
    first=temp;
    return;
}


void list:: deleteFront()
{
    if(first==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    if(first->link==NULL)
    {
        cout<<"Deleted node is "<<first->data;
        first=NULL;
        return;

    }

    node *previous=first;
     cout<<"Deleted node is "<<previous->data;
     first=first->link;
     delete previous;

}


void list::display()
{
    if(first==NULL)
    {
        cout<<"\nList is empty\n";
        return;
    }
    if(first->link==NULL)
    {
        cout<<"Data is "<<first->data;
        return;
    }
    node *temp=first;
    while(temp!=NULL)
    {
        cout<<"\nData is "<<temp->data;
        temp=temp->link;
    }
    cout<<"\n";
}


int main()
{
    int choice;
    list obj;
    for(;;)
    {
        cout<<"\nEnter 1 for insert 2 to delete 3 to exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: obj.insertFront();
                    obj.display();
                    break;
            case 2: obj.deleteFront();
                    obj.display();
                    break;
            case 3: exit(0);
        }
    }
    return 0;
}
