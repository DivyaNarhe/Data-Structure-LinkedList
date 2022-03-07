#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;
class SinglyCL
{
    private:
      PNODE first;
      PNODE last;
      int size;

    public:
      SinglyCL()
      {
          first =NULL;
          last=NULL;
          size=0;
      }
    void Display()
    {
        PNODE temp=first;
        if((first==NULL) &&(last==NULL))
        {
            return;
        }

        do{
            cout<<"|"<<temp->data<<"|->"<<"\t";
            temp=temp->next;
        }while (temp != last->next);   
        cout<<"NULL\n";
    }

    int Count()
    {
        return size;
    }

    void InsertFirst(int no)
     {
         PNODE newn=NULL;
         newn=new NODE;
         newn->next=NULL;
         newn->data=no;

         if((first==NULL) &&(last==NULL))
         {
             first=newn;
             last=newn;
         }
         else
         {
             newn->next=first;
             first=newn;
         }
           last->next=first;
           size++;
     }

     void InsertLast(int no)
     {
         PNODE newn=NULL;
         newn=new NODE;
         newn->next=NULL;
         newn->data=no;

         if((first==NULL) &&(last==NULL))
         {
             first=newn;
             last=newn;
         }
         else
         {
             PNODE temp=first;
            do
            {
                temp=temp->next;
            } while (first!=last->next);

            last->next=newn;
            last=newn;
            last->next=first;
            size++;
         }
     }

     void DeleteFirst()
     {
         PNODE temp=first;
         if((first==NULL) && (last==NULL))
         {
             return;
         }
         else if(temp->next==NULL)
         {
             delete first;
             first=NULL;
             last=NULL;
         }
         else
         {
             first=temp->next;
             delete temp;
         }
         last->next=first;
         size--;
     }
    void DeleteLast()
    {
        PNODE temp=first;
         if((first==NULL) && (last==NULL))
         {
             return;
         }
         else if(temp->next==NULL)
         {
             delete first;
             first=NULL;
         }
         else
         {
             while (temp->next!=last)
             {
                 temp=temp->next;
             }
             delete last;
             last=temp;

             last->next=first;
             size--;
         }
    }
    void InsertAtPos(int no,int Pos)
    {
        int i=0;

        if((Pos<1) ||(Pos>size+1))
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
            newn->next=NULL;
            newn->data=no;

            for(i=1 ;i<Pos-1;i++)
            {
                temp=temp->next;
            }
            newn->next=temp->next;
            temp->next=newn;
        }
        size++;
    }
    void DeleteAtPos(int Pos)
    {
        PNODE temp=first;

        if((Pos<1)||(Pos>size))
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
            for(int i=1 ;i<Pos-1;i++)
            {
                temp=temp->next;
            }
            PNODE targated=temp->next;

            temp->next=targated->next;
            delete targated;
        }
        size--;
    }
};
int main()
{
    SinglyCL obj;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.Display();

    obj.DeleteFirst();
    obj.Display();

    obj.InsertAtPos(75,3);
    obj.Display();

    obj.DeleteLast();
    obj.Display();

    obj.DeleteAtPos(3);
    obj.Display();

    return 0;
}
