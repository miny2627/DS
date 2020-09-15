public class DoublylinkedList {
	private Node head;
	private int size;
	public DoublylinkedList()
	{
		head=new Node(null);
		size=0;
	}
	private class Node {
		private Object data;
		private Node next;
		private Node prev;
		public Node(Object input)
		{
			this.data=input;
			this.next=null;
			this.prev=null;
		}
	}
	
	private Node node(int index)
	{
		if(index<0 || index>size)
			throw new IndexOutOfBoundsException("Index : "+index+", Size : " + size);
		Node temp=head;
		if(index<(size/2))
		{
			for(int i=0; i<=index; i++)
				temp=temp.next;
		}
		else
		{
			for(int i=size; i>index; i--)
				temp=temp.prev;	
		}
		return temp;
	}
	
	public void addFirst(Object input)
	{
		Node newNode=new Node(input);
		newNode.next=head.next;
		
		if(head.next!=null)
			head.next.prev=newNode;
		
		else
			head.prev=newNode;
		
		head.next=newNode;
		size++;
	}
	public void addLast(Object input)
	{
		add(size,input);
	}
	public void add(int index, Object input)
	{
		if(index==0)
		{
			addFirst(input);
			return;
		}
		else
		{
			Node temp1=node(index-1);
			Node temp2=temp1.next;
			Node newNode=new Node(input);
			temp1.next=newNode;
			newNode.prev=temp1;
			newNode.next=temp2;
			
			if(newNode.next!=null)
				temp2.prev=newNode;
			else
				head.prev=newNode;
			
			size++;
		}
	}
	public void add(Object input)
	{
		addLast(input);
	}
	public Object removeFirst()
	{
		Node temp=node(0);
		head.next=temp.next;
		
		if(head.next!=null)
			temp.next.prev=null;
		else
			head.prev=null;
		
		size--;
		return temp.data;
	}
	public Object remove(int index)
	{
		if(index==0)
			return removeFirst();
		else if(index<0 || index>=size)
			throw new IndexOutOfBoundsException("Index : " + index + ", Size : " + size);
		
		Node temp=node(index);
		Node delete=temp.prev;
		Node ne=temp.next;
		delete.next=ne;
		
		if(ne!=null)
		{
			ne.prev=delete;
		}
		else
			head.prev=delete;
		
		size--;
		return temp.data;
	}
	public boolean remove(Object input)
	{
		int nodeIndex=indexOf(input);
		if(nodeIndex==-1)
			return false;
		else
		{
			remove(nodeIndex);
			return true;
		}
	}
	public Object removeLast()
	{
		return remove(size-1);
	}
	public Object get(int index)
	{
		Node temp=node(index);
		return temp.data;
	}
	public Object getFirst()
	{
		return get(0);
	}
	public int indexOf(Object data)
	{
		if(size<=0) return -1;
		
		int index=0;
		Node temp=head.next;
		Object no=temp.data;
		
		while(!data.equals(no))
		{
			temp=temp.next;
			
			if(temp==null)
				return -1;
			
			no=temp.data;
			index++;
		}
		return index;
	}
	public int getLength()
	{
		return size;
	}
	public String toString()
	{
		StringBuffer result=new StringBuffer("[");
		Node temp=head.next;
		
		if(temp!=null)
		{
			result.append(temp.data);
			temp=temp.next;
			
			while(temp!=null)
			{
				result.append(" ");
				result.append(temp.data);
				temp=temp.next;
			}
		}
		result.append("]");
		return result.toString();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DoublylinkedList list=new DoublylinkedList();
		list.add(10);
		list.add(20);
		list.add(30);
		list.add(40);
		list.add(50);
		System.out.println(list);
		
		list.add(2,60);
		list.addFirst(70);
		System.out.println(list);
		
		System.out.println(list.get(4));
		
		list.remove(2);
		list.remove(new Integer(40));
		System.out.println(list);
		
		list.removeFirst();
		list.removeLast();
		System.out.println(list);
		
		System.out.println("Å©±â "+list.getLength());
	}

}
