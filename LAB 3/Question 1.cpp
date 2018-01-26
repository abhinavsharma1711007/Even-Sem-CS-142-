#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* last;
};

class dll
{
	node* head;
	node* tail;

public:

	dll()
	{
		head = NULL;
		tail = NULL;
	}

	void insert( int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;
		if( head != NULL)
		{
			tail->next = temp;
			temp->last = tail;
			tail = temp;
		}
		else
		{
			temp->last = NULL;
			head = temp;
			tail = temp;
		}
	}

	void insertAt(int pos, int value)
	{
		node* temp = new node;
		node* temp2 = head;
		node* temp3;
		temp-> data = value;
		if(pos==1)
		{
			temp->last = NULL;
			temp->next = head;
			head->last = temp;
			head = temp;
		}
		else
		{
			while( pos > 2)
			{
				temp2 = temp2->next;
				pos--;
			}
			temp3 = temp2->next;
			temp->next = temp3;
			temp->last = temp2;
			temp2->next = temp;
			temp3->last = temp;
		}
	}

	void delet()
	{
		node* temp = tail->last;
		temp->next = NULL;
	}

	void deleteAt( int pos)
	{
		node * temp;
		temp = head;
		for( int i=2; i<pos; i++)
			temp = temp->next;
		node *del;
		del = temp->next;
		temp->next = del->next;
		node * nex;
		nex = del->next;
		nex->last = temp;
		delete del;
	}

	int countItem()
	{
		int n = 1;
		node* temp = head;
		while( temp->next != NULL)
		{
			n++;
			temp = temp->next;
		}
		return(n);
	}

	void display()
	{
		node* temp = head;
		while(temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL";
	}
};

int main()
{
	char c;
	dll list_1;
	int value, pos;
	cout << " Enter 'a' for INSERT. \n";
	cout << " Enter 'b' for INSERT AT. \n";
	cout << " Enter 'c' for DELETE. \n";
	cout << " Enter 'd' for DELETE AT. \n";
	cout << " Enter 'e' for COUNT ITEM. \n";
	cout << " Enter 'f' for DISPLAY. \n";
	cout << " Enter 'z' for EXIT. \n";
	while( c != 'z')
	{
		cout << "Enter command here:-	";
		cin >> c;
		if( c=='a')
		{
			cout << "Enter the value here:-	";
			cin >> value;
			list_1.insert(value);
		}
		else if ( c=='b')
		{
			cout << "Enter the value here:-	";
			cin >> value;
			cout << "Enter the position here:-	";
			cin >> pos;
			if( pos > list_1.countItem())
				cout << "This position is not possible.";
			else
				list_1.insertAt( pos , value);
		}
		else if ( c == 'c')
			list_1.delet();
		else if (c == 'd')
		{
			cout << "Enter the position here:-	";
			cin >> pos;
			if( pos < list_1.countItem())
				list_1.deleteAt(pos);
			else if(pos == list_1.countItem())
				list_1.delet();
		}
		else if (c == 'e')
			cout << list_1.countItem();
		else if (c == 'f')
			list_1.display();
		else if (c == 'z')
			cout << "BYE";
		else
			cout << "COMMAND INVALID";
	}
	return 0;
}
