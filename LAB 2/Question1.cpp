#include<iostream>
using namespace std;

class node
{
public:
	int element;
	node *next;
};

class list
{
private:
	node *head;
	node *end;
public:
	list()
	{
		head = NULL;
		end = NULL;
	}

	void insert(int data)
	{
		node *temp = new node;
		temp->element = data;
		if(head == NULL)
		{
			head=temp;
			end=temp;
			temp->next=NULL;
		}
		else
		{
			end->next=temp;
			temp->next=NULL;
			end = temp;
		}
	}

	void insertat(int pos, int data)
	{
		node *temp = new node;
		node *past = new node;
		past = head;
		temp->element=data;
		for(int i=2;i<pos;i++)
		{
			past=past->next;
		}
		temp->next = past->next;
		past->next = temp;
	}

	void del()
	{
		node *current=new node;
		node *previous=new node;
		current=head;
		while(current->next!=NULL)
		{
			previous=current;
			current=current->next;	
		}
		end=previous;
		previous->next=NULL;
		delete current;
	}

	void deleteat(int pos)
	{
  		node *current=new node;
  		node *previous=new node;
  		current=head;
  		for(int i=1;i<pos;i++)
  		{
  			previous=current;
  			current=current->next;
  		}
  		previous->next=current->next;
  	}

  	void countItems()
  	{
  		int n=0;
  		node *temp= new node;
  		temp = head;
  		while(temp!=NULL)
  		{
  			n++;
  			temp=temp->next;
  		}
  		cout << n;
  	}

  	void display()
  	{
  		node *temp=new node;
  		temp=head;
  		while(temp!=NULL)
  		{
  			cout << temp->element<<" ->";
  			temp = temp->next;
  		}
  		cout << "NULL";
  	}
};

int main()
{
	int value,position;
	char option;
	list mylist;
	cout << "(a) -- insert.		";
	cout << "(b) -- insertat.	";
	cout << "(c) -- delete.		";
	cout << "(d) -- deleteAt.	";
	cout << "(e) -- countItems.	";
	cout << "(f) -- dislpay.	";
	cout << "(g) -- exit	";
	while (option != 'g')
	{
		cin >> option;
		if(option=='a')
		{
			cout << "Enter Value";
			cin >> value;
			mylist.insert(value);
		}
		else if(option=='b')
		{
			cout << "Enter Value";
			cin >> value;
			cout << "Enter position";
			cin >> position;
			mylist.insertat(position,value);
		}
		else if(option=='c')
			mylist.del();
		else if(option=='d')
		{
			cout << "Enter position";
			cin >> position;
			mylist.deleteat(position);
		}
		else if(option=='e')
			mylist.countItems();
		else if(option=='f')
			mylist.display();
		else if(option== 'g')
			cout << "Bye";
		else
			cout << "Invalid option";
	}
return 0;
}
