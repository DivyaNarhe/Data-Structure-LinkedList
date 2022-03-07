class Node
{
    public int data;
    public Node next;
    public Node prev;
}
class DoublyLinear
{
    private Node first;
    private int size;

    public DoublyLinear()
    {
        this.first=null;
        this.size=0;
    }
    public void Display()
    {
        Node temp=first;

        while(temp!=null)
        {
            System.out.print("|"+temp.data+"|->");
            temp=temp.next;
        }
        System.out.print("null\n");
    }
    public int Count()
    {
        return this.size;
    }
    public void InsertFirst(int no)
    {
        Node newn =new Node();
        newn.data=no;
        newn.next=null;
        newn.prev=null;
        if(first==null)
        {
            first=newn;
        }
        else
        {
            newn.next=first;
            first.prev=newn;
            first=newn;
        }
        this.size++;

    }
    public void InsertLast(int no)
    {
         Node newn =new Node();
        newn.data=no;
        newn.next=null;
        newn.prev=null;

        if(first==null)
        {
            first=newn;
        }
        else
        {
            Node temp=first;
            while(temp.next !=null)
            {
                temp=temp.next;
            }
            temp.next=newn;
            temp.next.prev=temp;
        }
        this.size++;
    }
    public void InsertAtPos(int no,int ipos)
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
            Node newn=new Node();
            Node temp=first;
            newn.data=no;
            newn.next=null;
            newn.prev=null;

            for(int i=1 ;i<ipos-1 ;i++)
            {
                temp=temp.next;
            }
            newn.next=temp.next;
            newn.next.prev=newn;
            newn.prev=temp;
            temp.next=newn;   
        }
        this.size++;
    }
    public void DeleteFirst()
    {
        if(size==0)
        {
            return;
        }

        if(size==1)
        {
            first=null;
        }
        else
        {
            first=first.next;
        }
        this.size--;
    }
    public void DeleteLast()
    {
        if(size==0)
        {
            return;
        }

        if(size==1)
        {
            first=null;
        }
        else
        {
            Node temp=first;

            while(temp.next.next !=null)
            {
                temp=temp.next;
            }
            temp.next=null;
        }
        this.size--;
    }
    public void DeleteAtPos(int ipos)
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
            Node temp=first;

            for(int i=1 ;i<ipos-1 ;i++)
            {
                temp=temp.next;
            }
            temp.next=temp.next.next;
            temp.next.prev=temp;

            this.size--;
        }
    }
}
class DLinear
{
    public static void main(String arg[])
    {
        DoublyLinear obj=new DoublyLinear();
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();

        obj.InsertLast(101);
        obj.Display();

        obj.InsertAtPos(75,3);
        obj.Display();

        obj.DeleteAtPos(3);
        obj.Display();

        obj.DeleteLast();
        obj.Display();

        obj.DeleteFirst();
        obj.Display();

        obj.DeleteAtPos(1);
        obj.Display();


    }
}