#include<iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
private:
    node <T>* first;
    int size;
    
public:
    SinglyLL();
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
 SinglyLL<T>::SinglyLL()
   {
       first = NULL;
       size = 0;
   }
   
    template <class T>
   void SinglyLL<T>::InsertFirst(T no)
   {
        node <T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
       
       newn->data = no;
       newn->next = NULL;
       
       if(first == NULL)
       {
           first = newn;
       }
       else
       {
           newn->next = first;
           first = newn;
       }
       size++;
   }
   
    template <class T>
   void SinglyLL<T>::InsertLast(T no)
   {
        node <T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
       
       newn->data = no;
       newn->next = NULL;
       
       if(first == NULL)
       {
           first = newn;
       }
       else
       {
            node <T>* temp = first;
           
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next = newn;
       }
       size++;
   }
   
    template <class T>
   void SinglyLL<T>::InsertAtPos(T no, int ipos)
   {
       if((ipos<0) ||(ipos>size+1))
       {
           return ;
       }
       if(size==1)
       {
            InsertFirst(no);  
       }
       else if(size==size+1)
       {
            InsertLast(no);
       }
       else
       {
        node <T> * newn = new node<T>; 
        node <T> *temp=first;
        newn->data = no;
        newn->next = NULL;

       for(int i=1 ;i < ipos-1 ;i++)
       {
           temp=temp->next;
       }
       newn->next=temp->next;
       temp->next=newn;    
       }
       size++;
   }
   
    template <class T>
   void SinglyLL<T>::DeleteFirst()
   {
        node <T> * temp = first;
       
       if(first != NULL)
       {
           first = first->next;
           delete temp;
           
           size--;
       }
   }

    template <class T>
   void SinglyLL<T>::DeleteLast()
   {
        node <T>* temp = first;
       
       if(first == NULL)
       {
           return;
       }
       else if(first->next == NULL)
       {
           delete first;
           first = NULL;
           size--;
       }
       else
       {
           while(temp->next->next != NULL)
           {
               temp = temp->next;
           }
           
           delete temp->next;
           temp->next = NULL;
           size--;
       }
   }
   
    template <class T>
   void SinglyLL<T>::DeleteAtPos(int ipos)
   {
       if((ipos<0) ||(ipos>size))
       {
           return ;
       }
       if(ipos==1)
       {
           DeleteFirst();
       }
       else if(ipos==size)
       {
           DeleteLast();
       }
       else
       {
           node <T>* temp = first;
           node <T>* target=NULL;
           int i=0;
           for(i=1 ;i <ipos-1 ;i++)
           {
               temp=temp->next;
           }
           target=temp->next;
           temp->next=target->next;
           delete target;

           size--;
       }
       
   }
   
    template <class T>
   void SinglyLL<T>::Display()
   {
        node <T> * temp = first;
       
       while(temp!= NULL)
       {
           cout<<temp->data<<"\t";
           temp = temp->next;
       }
       cout<<"\n";
   }
   
    template <class T>
   int SinglyLL<T>::Count()
   {
       return size;
   }

/////////////////////////////////////////////
 
int main()
{
    SinglyLL<int>obj;
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



















/*
 Type 1
 
 wihle(temp!= NULL)
 {
    temp = temp->next;
 }
 
 --------------------------------------
 
 Type 2
 
 while(temp->next != NULL)
 {
    temp = temp->next;
 }
 
 ---------------------------------------
 
 Type 3
 
while(temp->next->next != NULL)
 {
 temp = temp->next;
 }
 
 
 
 */










