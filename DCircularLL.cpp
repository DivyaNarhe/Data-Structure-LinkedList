#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}NODE,*PNODE,**PPNODE;

class DCircularLL
{
    private:
     PNODE first;
     PNODE last;
     int size;

    public:

    DCircularLL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int ,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};
DCircularLL::DCircularLL()
{
    first=NULL;
    last=NULL;
    size=0;
}
void DCircularLL::Display()
{
    PNODE temp=first;

    for(int i=1 ;i<=size;i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
    
}
int DCircularLL::Count()
{
    return size;
}
void DCircularLL::InsertFirst(int no)
{
    PNODE newn=new NODE;
    newn->next=NULL;
    newn->data=no;
    newn->prev=NULL;

    if((first==NULL) &&(last==NULL))
    {
        first=newn;
        last=newn;
    }
    else{
        newn->next=first;
        newn->next->prev=newn;
        first=newn;
    }
    last->next=first;
    first->prev=last;
    size++;
}
void DCircularLL::InsertLast(int no)
{
    PNODE newn=new NODE;
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;
    PNODE temp=first;

    if((first==NULL) &&(last==NULL))
    {
        first=newn;
        last=newn;
    }
    else{
        last->next=newn;
        newn->prev=last;
        last=newn;
    }
    last->next=first;
    first->prev=last;
    size++;
}
void DCircularLL::InsertAtPos(int no,int Pos)
{
    if((Pos<1)||(Pos>size+1))
    {
        return;
    }
    if(Pos==1)
    {
        InsertFirst(no);
    }
    else if(Pos==size+1)
    {
        InsertLast(no);
    }
    else{
        PNODE newn=new NODE;
        PNODE temp=first;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(int i=1;i<Pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
    }
    size++;
}
void DCircularLL:: DeleteFirst()
{
    PNODE temp=first;

    if((first==NULL) &&(last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
        first=first->next;
        delete last->next;
    }
    last->next=first;
    first->prev=last;
    size--;
}
void DCircularLL::DeleteLast()
{
    PNODE temp=first;

    if((first==NULL) &&(last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
        while (temp->next!=last)
        {
            temp=temp->next;
        }
        delete last;
        last=temp;
    }
    last->next=first;
    first->prev=last;
    size--;
}
void DCircularLL::DeleteAtPos(int Pos)
{
    if((Pos<1)||(Pos>size+1))
    {
        return;
    }
    if(Pos==1)
    {
        DeleteFirst();
    }
    else if(Pos==size)
    {
        DeleteLast();
    }
    else{
        PNODE targated=NULL;
        PNODE temp=first;
        for(int i=1;i<Pos-1;i++)
        {
            temp=temp->next;
        }
        targated=temp->next;
        temp->next=targated->next;
        delete targated;
        temp->next->prev=temp;
    }
    size--;
}
int main()
{
    DCircularLL obj;
    int iret=0;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.Display();
    iret=obj.Count();
    cout<<"No of node is:"<<iret<<"\n";
    obj.InsertAtPos(75,3);
    obj.Display();
    iret=obj.Count();
    cout<<"No of node is:"<<iret<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iret=obj.Count();
    cout<<"No of node is:"<<iret<<"\n";

    obj.DeleteLast();
    obj.Display();
    iret=obj.Count();
    cout<<"No of node is:"<<iret<<"\n";

    obj.DeleteAtPos(2);
    obj.Display();
    iret=obj.Count();
    cout<<"No of node is:"<<iret<<"\n";

    return 0;
}