#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
     
        node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        ~node()
        {
            if(this->next != NULL)
            {
                delete next;
                this->next = NULL;
            }
        }
};  

void NodeAtTail(node* &Tail, int d)
{
    node* temp =  new node(d);
    Tail->next = temp;
    temp = Tail;
}

void NodeAtHead(node* &head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtpos(node* &head, node* &tail, int pos, int d)
{
    node *temp = head;
    if(pos == 1)
    {
        NodeAtHead(head,d);
        return;
    }

    if(temp->next == NULL)
    {
        NodeAtTail(tail,d );
        return;
    }
    int cnt=1;
    while(cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }

    node *newnode = new node(d);
    newnode->next = temp->next;
    temp ->next = newnode;
    

    
}

void deletePos(int pos, node *&head)
{
    if(pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;
        while(cnt < pos)
        {
            prev = curr;
            curr = curr->next; 
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL; 
        delete curr;
        
    }
}
    void printLL(node* &head)  
    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp ->next; 
        }
    }

node* reverseLL(node *head)
{
    node* prev = NULL;
    node* curr = head;
    node* forward = curr;
    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main()
{
    node *node1 = new node(0);
    node *head = node1;
    node *Tail = node1;


    NodeAtHead(head, 20);
    NodeAtHead(head, 30);
    NodeAtHead(head, 40);
    NodeAtTail(Tail, 50);   
    insertAtpos(head, Tail , 3, 87);
    printLL(head);
    cout<<endl;
    node* p = reverseLL(head);
    printLL(p);
    
    
return 0;
}
 