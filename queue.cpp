#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;
class Queue
{
    private:
    PNODE first;
    int size;

    public:
    Queue()
    {
        first=NULL;
        size=0;
    }
    void Enqueue(int no)
    {
        PNODE temp=first;
        PNODE newn=new NODE;
        newn->next=NULL;
        newn->data=no;

        if(first==NULL)
        {
            first=newn;
        }
        else{
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;
        }
        size++;
    }
    int Dequeue()
    {
        int no=0;
        PNODE temp=first;
        if(first==NULL)
        {
            return -1;
        }
        else 
        {
            no=first->data;
            first=first->next;
            delete temp;
        }
        return no;
        size--;
    }
    void Display()
    {
         PNODE temp=first;
        while (temp !=NULL)
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

};
int main()
{
    Queue obj;
    int iret=0;
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(31);
    obj.Enqueue(51);

    obj.Display();
    iret=obj.Dequeue();
    cout<<"Dequeue element is:"<<iret<<"\n";

    obj.Display();

    return 0;
}