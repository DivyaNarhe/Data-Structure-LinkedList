#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}NODE ,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn=NULL;
    newn =(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head =newn;
    }
    else
    {
        newn->next=*Head;
        *Head=newn;
    }
}
int Count(PNODE Head)
{
    int iCount=0;
    while (Head !=NULL)
    {
        iCount++;
        Head =Head->next;
    }
    return iCount;
    
}
void Display(PNODE Head)
{
    while (Head !=NULL)
    {
        printf("|%d| ->",Head->data);
        Head =Head->next;
    }
    printf("NULL");
    
}

void InsertLast(PPNODE Head,int no)
{
    PNODE temp=*Head;
    PNODE newn=NULL;
    newn =(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head =newn;
    }
    else
    {
        while (temp->next!=NULL)
        {
           temp=temp->next;
        }
        temp->next=newn;
    }
}

void InsertAtPos(PPNODE Head,int no,int iPos)
{
    PNODE temp=*Head;
    PNODE newn=NULL;
    int size=0,i=0;
    size =Count(*Head);

    if((iPos<1) || (iPos>size+1))
    {
        return;
    }
    if(iPos ==1)
    {
        InsertFirst(Head,no);
    }
    else if(iPos ==size +1)
    {
        InsertLast(Head,no);
    }
    else
    {
        newn =(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        for(i =1 ;i<iPos-1 ;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

    }

}
int SinglyLLAddition(PNODE Head )
{
    int sum=0,i=0,size=0;
    size=Count(Head);

    while (Head !=NULL)
    {
        for(i=1 ;i<=size ;i++)
        {
            sum =Head->data +sum;
            Head= Head->next;
        } 
        return sum;
    }
}
int main()
{
  PNODE first =NULL;
    int iRet=0,iChoice=1,value=0,pos=0;
 
    while (iChoice !=0)
    {
        printf("\n **********************************************\n");
        printf("\n Enter Your Choice..\n");
        printf("1 : Insert element at First Position \n");
        printf("2 : Insert element at Last Position \n");
        printf("3 : Insert element at Given Position \n");
        printf("4 : Display Addition of all elements present in LinkdeList\n");
        printf("5 : Display all contents of LinkedList \n");
        printf("6 : Count no of nodes present in Linked list \n");
        printf("0 : Terminate application\n");
        printf("\n **********************************************\n");

    scanf("%d",&iChoice);

    switch (iChoice)
    {
    case 1:
        printf("Enter data to Insert at First Position\n");
        scanf("%d",&value);
        InsertFirst(&first,value);
        break;

    case 2:
        printf("Enter data to Insert at Last Position\n");
        scanf("%d",&value);
        InsertLast(&first,value);
        break;
    
    case 3:
        printf("Enter data to Insert at Given Position\n");
        scanf("%d",&value);
        printf("Enter Position\n");
        scanf("%d",&pos);
        InsertAtPos(&first,value,pos);
        break;
    
    case 4:
        iRet=SinglyLLAddition(first);
        printf("Addition of all elements is:%d\n",iRet);
        break;

    case 5:
        printf("All elements Present in LinkedList\n");     
        Display(first);
        break;

    case 6:
        iRet =Count(first);
        printf("No of nodes in LinkedList is:%d\n",iRet);
        break;

    case 0:
        printf("Application terminated Sucessfully !!!!!!\n");
        break;


    default:
       printf("Please enter Proper Choice\n");
        break;
    }
    }


    return 0;
}