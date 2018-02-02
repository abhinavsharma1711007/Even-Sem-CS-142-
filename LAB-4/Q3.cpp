#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
};

class stackLL
{
	node *top;

public:
	stackLL()
	{
		top =NULL;
	}
	void push(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if(top!=NULL)
		{
			temp->next = top;
		}
		top = temp;
	}
	void pop(){

	}
	void show(){
		node *curr = top;
		while (curr!=NULL){
			cout << curr->data << "->" ;
			curr = curr->next;
		}
		
		cout << "NULL" <<endl;
	}
	void empty(){

	}
};

class queueLL
{
	node *head;
    node *tail;

public:
	queueLL()
	{
		head = NULL;
        tail = NULL;
	}
	void inqueue(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
        if (head!=NULL)
        {
            tail->next = temp;
        }
        else
        {
        head = temp;
        }
        tail = temp;
	}
	void dequeue()
	{

	}
    void fun1(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        fun1(temp->next);
        cout << temp->data << "->";
    }
	void show()
	{
        fun1(head);
		node *curr = head;
		while (curr!=NULL){
			cout << curr->data << "->" ;
			curr = curr->next;
		}
		cout << "NULL" <<endl;
	}
};
