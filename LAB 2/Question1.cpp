#include<iostream>

using namespace std;

class node
{  public :
    int data;
    node *next;
};

class link
{
    node *head;
    node *tail;

    link ()
    {
      head = NULL;
      tail = NULL;
    }
    public :
       void insert_list(int data);
       void insert_at(int pos, int data);
       void delete_list();
       void delete_at(int pos);
       void display_l();
       void count_l();
};

int main()
{ char ch;
  cout<<"Choose what you want to do : "<<endl;
  cout<<"(a) create a linked list."<<endl;
  cout<<"(b) insert data in linked list."<<endl;
  cout<<"(c) insert a data at any position. "<<endl;
  cout<<"(d) delete the linked list. "<<endl;
  cout<<"(e) delete data of a specific position."<<endl;
  cout<<"(f) display the elements of linked list."<<endl;
  cout<<"(g) count the number of elements in the list."<<endl;
  cin>> ch;
     if (ch=='a')
     {
        cout<<"Linked list created."<<endl;
     }
     else if (ch=='b')
     {
         int num;
         link in_l;
         cout<<"How many data do you want to add ?"<<endl;
         cin>>num;
         for(int i=1;i<=num;i++)
         {   int data;
             cout<<"Data "<<i<<" = ";
             cin >> data;
             in_l.insert_list(data);
         }
     }

return 0;
}

void link :: insert_list(int data)
{
     node *temp = new node;
     temp->data = data;
     if (head == NULL)
     {
         head=temp;
         tail=temp;
         temp->next = NULL;
     }
     else
        {
           tail->next = temp;
           temp->next = NULL;
           tail=temp;
        }
}

void link :: insert_at(int pos, int dat)
{
    node *tmp =new node;
    node *pos;
    pos=head;
    tmp->data= dat;
    for (int i=2;i<pos;i++)
    {
        pos=pos->next;
    }
    tmp->next = pos->next;
    pos->next = tmp;
}

void link :: delete_list()
{
    node *pos;
    pos=head;
    while (pos->next != tail)
    {
        pos=pos->next;
    }
    tail=pos;
    pos=pos->next;
    tail->next = NULL;
    delete pos;

}

void link :: delete_at(int post)
{ node *pos;
  pos=head;
  for (int i=2;i<post;i++)
  {
      pos=pos->next;
  }
  node *temp;
  temp = pos->next;
  pos->next = temp->next;
  temp->next = NULL;
  delete temp;
}

void link :: display_l()
{
    node *pos;
    pos=head;
    cout<<pos->data<<" -> ";
    while (pos->next = NULL)
    {
        pos=pos->next;
        cout<<pos->data<<" -> ";
    }
}

void link :: count_l()
{

}
