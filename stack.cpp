#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;
class Stack
{
    private:
    PNODE first;
    int size;

    public:
    Stack()
    {
        first=NULL;
        size=0;
    }
    void Push(int no)
    {
        PNODE newn=new NODE;

        newn->next=NULL;
        newn->data=no;

        if(first==NULL)
        {
            first=newn;
        }
        else{
            newn->next=first;
            first=newn;
        }
        size++;
    }

    int Pop() //Deletefirst
    {
        int no=0;
        PNODE temp=first;
        if(first==NULL)//(size==0)
        {
            return -1;
        }
        else if(first->next==NULL)//if(size==1)
        {
            no=first->data;
            delete first;
            first=NULL;
        }
        else{
            no=first->data;
            first=first->next;
            delete temp;
        }
        size--;
        return no;
    }

    void Display()
    {
       PNODE temp=first;
       while(temp!= NULL)
       {
           cout<<"|"<<temp->data<<"|"<<"\n";
           temp=temp->next;
       }

    }
    int Count()
    {
        return size;
    }

};
int main()
{
    Stack obj;
    obj.Push(11);
    obj.Push(21);
    obj.Push(31);
    obj.Push(51);

    cout<<"Elements of stack\n";
    obj.Display();

    int iRet=obj.Pop();
    cout<<"Poped element is:"<<iRet<<"\n";

     cout<<"Elements of stack\n";
    obj.Display();
    iRet=obj.Count();
    cout<<"Size is:"<<iRet<<"\n";
    
    return 0;
}