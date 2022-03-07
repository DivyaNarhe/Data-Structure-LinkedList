#include <iostream>
using namespace std;

template <typename T>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLL
{
private:
    node<T> *first;
    int size;

public:
    DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    size = 0;
}
template <class T>
void DoublyLL<T>::Display()
{
    node<T> *temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->"
             << "\t";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return size;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    node<T> *newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }
    size++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    node<T> *newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    node<T> *temp = first;
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev=temp;
        temp->next = newn;
        
    }
    size++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first==NULL)
    {
        return;
    }
    else if(first->next==NULL)
    {
       delete first;
       first=NULL;
    }
    else
    {
        first=first->next;
        delete first->prev;
        first->prev=NULL;
    }
    size--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    node <T>* temp=first;
    if(first==NULL)
    {
        return;
    }
    else if(first->next==NULL)
    {
       delete first;
       first=NULL;
    }
    else
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
    }
    size--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos<0) ||(ipos>size))
    {
        return;
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
        node <T>* temp=first;
        //node <T>* temp=first;
        for(int i=1 ;i< ipos-1 ;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
    }
    size--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int ipos)
{
    if ((ipos < 0) || (ipos > size + 1))
    {
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        node<T> *newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        node<T> *temp = first;

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
         size++;
    }
   
}

int main()
{
    DoublyLL<int> obj;
    int iChoice = 1, value = 0, iRet = 0, pos = 0;

    while (iChoice != 0)
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

        cin >> iChoice;
        switch (iChoice)
        {
        case 1:
            cout << "Enter data to insert\n";
            cin >> value;
            obj.InsertFirst(value);
            break;

        case 2:
            cout << "Enter data to insert\n";
            cin >> value;
            obj.InsertLast(value);
            break;

        case 3:
            cout << "Enter data to insert\n";
            cin >> value;
            cout << "Enter Position\n";
            cin >> pos;
            obj.InsertAtPos(value, pos);
            break;

        case 4:
            obj.DeleteFirst();
            break;

        case 5:
            obj.DeleteLast();
            break;

        case 6:
            printf("Enter the position:\n");
            scanf("%d", &pos);
            obj.DeleteAtPos(pos);
            break;

        case 7:
            printf("All contents in Linked list \n");
            obj.Display();
            break;

        case 8:
            iRet = obj.Count();
            printf("Number of element is:%d", iRet);
            break;

        case 0:
            printf("Thank you!!!!\n");
            break;

        default:
            printf("Please enter valid choice\n");
            break;
        }
    }

   /* DoublyLL<float> obj1;
   // int iChoice = 1,iRet = 0, pos = 0;
    float val=0.0;

    while (iChoice != 0)
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

        cin >> iChoice;
        switch (iChoice)
        {
        case 1:
            cout << "Enter data to insert\n";
            cin >> val;
            obj1.InsertFirst(val);
            break;

        case 2:
            cout << "Enter data to insert\n";
            cin >> val;
            obj1.InsertLast(val);
            break;

        case 3:
            cout << "Enter data to insert\n";
            cin >> val;
            cout << "Enter Position\n";
            cin >> pos;
            obj1.InsertAtPos(val, pos);
            break;

        case 4:
            obj1.DeleteFirst();
            break;

        case 5:
            obj1.DeleteLast();
            break;

        case 6:
            printf("Enter the position:\n");
            scanf("%d", &pos);
            obj1.DeleteAtPos(pos);
            break;

        case 7:
            printf("All contents in Linked list \n");
            obj1.Display();
            break;

        case 8:
            iRet = obj1.Count();
            printf("Number of element is:%d", iRet);
            break;

        case 0:
            printf("Thank you!!!!\n");
            break;

        default:
            printf("Please enter valid choice\n");
            break;
        }
    }*/
    return 0;
}