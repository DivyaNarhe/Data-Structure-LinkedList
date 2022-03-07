class Node
{
	public int data;
	public Node next;
}

class SinglyCL
{
    private Node first;
    private Node last;
    private int size;

    public SinglyCL()
    {
        this.first=null;
        this.last=null;
        this.size=0;
    }
    public void Display()
    {
        Node temp=first;
        if((first==null) &&(last==null))
        {
            return;
        }
        do
        {
            System.out.print("|"+temp.data+"|-> ");
			temp = temp.next;
        }while(temp!=last.next);
        System.out.println("null");
    }
    
    public int Count()
    {
        return this.size;
    }
    public void InsertFirst(int no)
    {
         Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;

		if((first == null) &&(last==null))
		{
			first = newn;
            last =newn ;
		}
		else
		{
			newn.next=first;
            first=newn;
		}
        last.next=first;
		this.size++;
    }

    public void InsertLast(int no)
    {
         Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;

		if((first == null) &&(last==null))
		{
			first = newn;
            last =newn ;
		}
		else
		{
			Node temp=first;
            do
            {
                temp=temp.next;
            }while(first !=last.next);
		}
        last.next=newn;
        last=newn;
        last.next=first;
		this.size++;
    }
    public void InsertAtPos(int no,int ipos)
    {
        if((ipos <0)||(ipos>size+1))
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
            Node newn= new Node();
            newn.data=no;
            newn.next=null;

            Node temp=first;
            int i=0;
            for(i =1 ;i<ipos-1 ;i++)
            {
                temp=temp.next;
            }
            newn.next=temp.next;
            temp.next=newn;
            this.size++;
        }

    }
    public void DeleteFirst()
    {
        if(size == 0)
		{
			return;
		}

		if(size == 1)
		{
			first = null;
            last= null;
		}
		else
		{
			first = first.next;
		}
        last.next=first;
		this.size--;
    }
    public void DeleteLast()
    {
        if(size == 0)
		{
			return;
		}

		if(size == 1)
		{
			first = null;
            last =null;
		}
		else
		{
            Node temp=first;
            while(temp.next !=last)
            {
                temp=temp.next;
            }
            last=temp;
            last.next=first;
            this.size--;
        }
    }

    
	public void DeleteAtPos(int ipos)
	{
		if((ipos < 0) || (ipos > size))
		{
			return;
		}

		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{
			Node temp = first;

			for(int i =1; i < ipos-1; i++)
			{
				temp = temp.next;
			}

			temp.next = temp.next.next;

			this.size--;
		}
	}
}
class Program264
{
    public static void main(String arg[])
    {
         SinglyCL obj= new SinglyCL();
         obj.InsertFirst(51);
         obj.InsertFirst(21);
         obj.InsertFirst(11);
         obj.InsertLast(101);
         obj.Display();

         obj.InsertAtPos(75,3);
         obj.Display();
         obj.DeleteFirst();
         obj.Display();

         obj.DeleteLast();
         obj.Display();

         obj.DeleteAtPos(2);
         obj.Display();
    }
}