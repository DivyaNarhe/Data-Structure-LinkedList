#include<iostream>
using namespace std;

template <typename T>
struct node
{
    int data;
    struct node* next;
};
template <class T>
class SinglyCL
{
    private:
       node <T>* first;
       node <T>* last;
       int size;
    
    public:
      SinglyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
SinglyCL<T>:: SinglyCL()
{
    first=NULL;
    last=NULL;
    size=0;
}

template <class T>
void SinglyCL<T>:: Display()
{
    node <T>* temp=first;

    if((first==NULL)&&(last==NULL))
    {
        return;
    }

    do
    {
       cout<<"|"<<temp->data<<"|->"<<"\t";
       temp=temp->next;
    } while (temp !=last->next);
    cout<<"NULL";
    
}
template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    node <T>* newn= new node<T>;
    newn->data=no;
    newn->next=NULL;

    if((first== NULL) &&(last==NULL))
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

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    node <T>* newn= new node<T>;
    newn->data=no;
    newn->next=NULL;

    if((first== NULL) &&(last==NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        node <T>* temp=first;
        do{
            temp=temp->next;
        }while (first !=last->next);

        last->next=newn;
        last=newn;
    }
    last->next=first;
    size++;
}
template <class T>
int SinglyCL<T>::Count()
{
    return size;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos<0) ||(ipos>size+1))
    {
        return;
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        node<T>* newn=new node<T>;
        newn->data=no;
        newn->next=NULL;

        int i=0;
        node<T>* temp=first;
        for(i=1 ;i< ipos-1 ;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        size++;
    }

}
template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first==NULL) && (last==NULL))
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
        last->next=first;
    }
    size--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((first==NULL) && (last==NULL))
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
        node <T>* temp=first;
        while (temp->next !=last)
        {
            temp=temp->next;
        }
        delete last;
        last=temp;

        last->next=first;
    }
    size--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos<0)||(ipos>size))
    {
        return ;
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        node <T>* temp=first;
        node <T>* targated=NULL;
        int i=0;
        for(i=1 ;i < ipos-1 ;i++)
        {
            temp=temp->next;
        }
        targated =temp->next;
        temp->next=targated->next;
        delete targated;

        size--;
    }

}
int main()
{
    SinglyCL <int> obj;
     int iChoice=1,value=0,iRet=0,pos=0;

    while (iChoice!=0)
    {
        printf("\n-----------------------------------------------------------------\n");
        printf("Enter desired operation that you want to perform on linked list:\n");
        printf("1 : Insert Node at First\n");
        printf("2 : Insert Node at Last\n");
        printf("3 : Insert Node at given Position\n");
        printf("4 : Delete Node from First\n");
        printf("5 : Delete Node from Last\n");
        printf("6 : Delete Node from given Position\n");
        printf("7 : Display all contents from link list:\n");
        printf("8 : Count present node from linkedlist\n");
        printf("0 : Terminate application \n");
        printf("\n-----------------------------------------------------------------\n");

        cin>>iChoice;
        switch (iChoice)
        {
        case 1:
            cout<<"Enter data to insert\n";
            cin>>value;
            obj.InsertFirst(value);
            break;
        
        case 2:
            cout<<"Enter data to insert\n";
            cin>>value;
            obj.InsertLast(value);
            break;

        case 3:
            cout<<"Enter data to insert\n";
            cin>>value;
            cout<<"Enter Position\n";
            cin>>pos;
            obj.InsertAtPos(value,pos);
            break;

        case 4:
            obj.DeleteFirst();
            break;

        case 5:
            obj.DeleteLast();
            break;

        case 6:
           printf("Enter the position:\n");
           scanf("%d",&pos);
           obj.DeleteAtPos(pos);
            break;


        case 7:
            printf("All contents in Linked list \n");
            obj.Display();
            break;

        case 8:
            iRet=obj.Count();
            printf("Number of element is:%d",iRet);
            break;

        case 0:
           printf("Thank you!!!!\n");
           break;
        
        default:
        printf("Please enter valid choice\n");
            break;
        }
    }
    return 0;

}
