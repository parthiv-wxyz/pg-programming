#include<iostream>
using namespace std;
class list
{
    struct node
    {
        int data;
        node *link;
    } *start;
    public:
    list()
    {
        start=NULL;
    }
    void insert(int);
    void del(int);
    void traverse();
    ~list();
};
void list::insert(int item)
{
    node *temp, *ptr;
    temp=new node;
    temp->data=item;
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
    }
}
void list::del(int item)
{
    node *old, *temp;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            if(temp==start)
                start=start->link;
            else
                old->link=temp->link;
            delete temp;
            return;
        }
        else
        {
            old=temp;
            temp=temp->link;
        }
    }
    cout<<"\n Item not found";
}
void list::traverse()
{
    node *temp;
    temp=start;
    if(temp==NULL)
    {
        cout<<"\n List is empty";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->link;
    }
}
list::~list()
{
    node *temp;
    while(start!=NULL)
    {
        temp=start->link;
        delete start;
        start=temp;
    }
}
int main()
{
    list l;
    char ch1;
    int item,ch,pos;
    do
    {
        cout<<"\n 1.Insert \n 2.Delete \n 3.Traverse";
        cout<<"\n Enter your choice(numbers only): ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n Enter the item to be inserted: ";
                    cin>>item;
                    l.insert(item);
                    break;
            case 2: cout<<"\n Enter the item to be deleted: ";
                    cin>>item;
                    l.del(item);
                    break;
            case 3: l.traverse();
                    break;
            default:break;
        }
        cout<<"\n Do you want to continue (y/n): ";
        cin>>ch1;
    } 
    while (ch1=='y' || ch1=='Y');
}