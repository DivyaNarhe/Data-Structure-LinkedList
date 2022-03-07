#include<stdio.h>
#include<stdlib.h>
typedef struct  node
{
    int data;
    struct node* next;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
    while (Head !=NULL)
    {
        printf("|%d|->",Head->data);
        Head=Head->next;
    }
    printf("NULL\n");
}
int Count(PNODE Head)
{
    int icnt=0;
    while (Head !=NULL)
    {
        icnt++;
        Head=Head->next;
    }
   return icnt;
}
void InsertFirst(PPNODE Head,int no)
{
    PNODE newn=NULL;
    newn=(PNODE) malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if((*Head)==NULL)
    {
        *Head=newn;
    }
    else{
        newn->next=*Head;
        *Head=newn;
    }
}
void InsertLast(PPNODE Head,int no)
{
    PNODE newn=NULL;
    PNODE temp=*Head;
    newn=(PNODE) malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if((*Head)==NULL)
    {
        *Head=newn;
    }
    else {
        while (temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
}
void DeleteFirst(PPNODE Head)
{

    PNODE temp=*Head;
    if((*Head)==NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else{
        *Head=(*Head)->next;
        free(temp);
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE temp=*Head;
    if((*Head)==NULL)
    {
        return;
    }
    else if((*Head)->next ==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else{
        while (temp->next->next !=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;   
    }
}
void InsertAtPos(PPNODE Head,int no,int Pos)
{
    int size=0,i=0;
    PNODE newn=NULL;
    PNODE temp=*Head;
    size=Count(*Head);

    if((Pos<1) || (Pos>size+1))
    {
        return;
    }
    if(Pos==1)
    {
        InsertFirst(Head,no);
    }
    else if(Pos==size +1)
    {
        InsertLast(Head,no);
    }
    else
    {
        newn =(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        for(i=1 ;i<Pos-1 ;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}
void DeleteAtPos(PPNODE Head,int Pos)
{
    int i=0;
    PNODE targated=NULL;
    PNODE temp=*Head;
    int size=Count(*Head);
    if((Pos <1) ||(Pos>size))
    {
        return;
    }
    if(Pos==1)
    {
        DeleteFirst(Head);
    }
    else if(Pos==size)
    {
        DeleteLast(Head);
    }
    else
    {
        for(i=1; i<Pos-1;i++)
        {
            temp=temp->next;
        }
        targated=temp->next;

        temp->next=targated->next;
        free(targated);
    }
  
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    InsertLast(&first,101);
    InsertAtPos(&first,75,3);
    Display(first);

    DeleteAtPos(&first,3);
    DeleteFirst(&first);
    DeleteLast(&first);
    
    Display(first);
    int iRet=Count(first);
    printf("COUNT IS:%d",iRet);
    return 0;
}