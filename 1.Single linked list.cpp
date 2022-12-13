#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node * next;
	//constructor to create a node and assign data into it
	node(int data)
	{
		this -> data = data;
		this -> next = NULL;
	}
	//destructor
	~node()
	{
		int value = this->data;
		if(this-> next!=NULL)
		{
			delete next;
			this->next=NULL;
		}
		cout<<"Memory is deleted for "<<value;
	}
	
};
void insertathead(node * &head,int d)
{
	node* temp = new node(d);
	temp -> next=head;
	head=temp;
}
void insertatend(node * &tail,int d)
{
	node* temp =  new node(d);
	tail->next = temp;
	tail=temp;
}
void insert(node* &tail,node* &head,int pos,int data)
{
	if(pos==1)
	{
		insertathead(head,data);
		return;
	}
	node *temp=head;
	int cnt=1;
	while(cnt<pos-1)
	{
		temp = temp->next;
		cnt++;
	}
	if(temp->next == NULL)
	{
		insertatend(tail,data);
		return;
	}
	node *node2 = new node(data);
	node2 ->next = temp -> next;
	temp->next = node2;
	
	
}
void deletepos(int pos, node* &head)
{
	//deleting first node
	if(pos==1)
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
	else
	{
		//delete at last or middle
		node *curr = head;
		node *prev =NULL;
		int cnt=1;
		while(cnt<pos)
		{
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		prev->next=curr->next;
		curr->next=NULL;
		cout<<"hello";
		delete curr;
		cout<<"world";
		
	}
}

void print(node * &head)
{
	cout<<endl;
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


int main()
{
	node * node1 = new node (10);
	//cout<< node1-> data;
	node *head = node1;
	node *tail = node1;
	print(head);
	insertathead(head,12);
	print(head);
	insertatend(tail,15);
	print(head);
	cout<<"head = "<<head -> data <<endl<<"tail = "<< tail ->data<<endl;
	insert(tail,head,3,22);
	print(head);
	//deletepos(2,head);
	print(head);
}
