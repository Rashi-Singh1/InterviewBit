#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class list
{
private:
	node* head;
	node* tail;
public:
	list(){
		this->head = NULL;
		this->tail = NULL;
	}
	void addNode(int val);
	node* reverse();
	void print();
};

void list::addNode(int val)
{
	node* Node = new node(val);
	if(this->head == NULL)
	{
		this->head = Node;
		this->tail = Node;
	}
	else{
		this->tail->next = Node;
		this->tail = Node;
	}
}

void reverseUtil(node* prev, node* cur, node* nex)
{
    if(cur == NULL) return;
	cur->next = prev;
	if(nex) reverseUtil(cur,nex,nex->next);
	else reverseUtil(cur,nex,NULL);
}

node* list:: reverse()
{
	if(this->head == NULL) return this->head;
	reverseUtil(NULL,this->head,this->head->next);
	return this->tail;
}

void list::print()
{
	node* temp = this->head;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}cout<<endl;
}

int main(int argc, char const *argv[])
{
	list List;
	for(int i = 0;i<16;i++)
	{
		List.addNode(2*i);
	}
	List.print();
	node* temp = List.reverse();
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}cout<<endl;
	return 0;
}