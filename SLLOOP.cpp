#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;

class SinglyLL
{
    private:
      PNODE first;
      PNODE last;
      int size;

    public:
      SinglyLL()
      {
          first=NULL;
          last=NULL;
          size=0;
      }
    void Display()
    {
        PNODE temp=first;
        while (temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    int Count()
    {
        return size;
    }
    void InsertFirst(int no)
    {
        PNODE newn=NULL;
        newn= new NODE;
        newn->data=no;
        newn->next=NULL;

        if(first==NULL)
        {
            first=newn;
        }
        else
        {
            newn->next=first;
            first=newn;
        }
        size++;
    }
    void InsertLast(int no)
    {
        PNODE temp=first;
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=no;
        newn->next=NULL;

        if(first==NULL)
        {
            first=newn;
        }
        else
        {
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;
        }
        size++;
    }
    void InsertAtPos(int no,int Pos)
    {
        PNODE newn=NULL;
        PNODE temp=first;
        int i=0;
        if((Pos <1) ||(Pos>size+1))
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
        else
        {
            newn=new NODE;
            newn->data=no;
            newn->next=NULL;

            for(i =1 ;i<Pos-1 ;i++)
            {
               temp=temp->next;
            }
            newn->next=temp->next;
            temp->next=newn;
        }
        size++;
    }
    void DeleteFirst()
    {
        PNODE temp=first;

        if(first==NULL)
        {
            return;
        }
        else 
        {
            first=first->next;
            delete temp;
        }
        size--;
    }
    void DeleteLast()
    {
        PNODE temp=first;

        if(first==NULL)
        {
            return;
        }
        else if(first->next==NULL)
        {
            delete first;
            first=NULL;
            size--;
        }
        else
        {
            while (temp->next->next !=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
            size--;
        }
      
    }
    void DeleteAtPos(int Pos)
    {
        PNODE temp=first;
        int i=0;

        if((Pos <1) ||( Pos>size+1))
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
        else
        {
            PNODE targated=NULL;
            for(i=1 ;i<Pos-1;i++)
            {
                temp=temp->next;
            }
            targated=temp->next;
            temp->next=targated->next;
            delete targated;
        }
        size--;
        
    }
};

int main()
{
    SinglyLL obj;
    int iRet=0;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
   
    obj.InsertLast(5);
    obj.InsertAtPos(75,3);
    obj.Display();
    iRet=obj.Count();
    cout<<"No of node is:"<<iRet<<"\n";

    obj.DeleteAtPos(3);
    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    iRet=obj.Count();
    cout<<"No of node is:"<<iRet<<"\n";


    return 0;
}