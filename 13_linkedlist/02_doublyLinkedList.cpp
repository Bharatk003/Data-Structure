#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL; 
        }
    }
};



void print(node* head)
{
    node*temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(node *head)
{    
    int cnt =  0;
    node *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void InsertAthead(node* &head, int d)
{
    node* temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
    
}

void InsertAtTail(node* &tail, int d)
{
    node* temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp ;
}   


void atanyPos(node* &head,node* &tail,int pos, int d)
{
    if(pos == 1)
    {
        InsertAthead(head, d);
        return ;
    }
    int cnt = 1;
    node *temp = head;

    while(cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL)
    {
        InsertAtTail(tail, d);
    }

    node *newNode = new node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp -> next = newNode;   
}

void deleteNode(node* &head, int pos)
{
    if(pos == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        node*prevs = NULL;
        node* curr = head;
        int cnt=1;
        while(cnt<=pos-1)
        {
            prevs = curr;
            curr = curr->next;
            cnt++;    
        }
        prevs->next = curr->next;
        curr->next->prev=prevs;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    InsertAthead(head, 12);
    InsertAtTail(tail, 14);
    atanyPos(head, tail , 3, 16);
    deleteNode(head, 4);
    print(head);
    cout<<getlength(head);
 

return 0;
}