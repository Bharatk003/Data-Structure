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
    void print(node* &head)  
    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp ->next; 
        }
    }

    
bool isCircular(node *head)
{
    node* temp = head->next;
    
    if(temp == NULL );
    {
        return false;
    }
    if(temp->next == temp)
    {
        return true;
    }

    while(temp != NULL && temp != head)
    {
        temp = temp -> next;
    }
    if(temp == head)
    {
        return true;
    }
    return false;
    
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
    print(head);
    cout<<endl;
    deletePos(3, head);
    print(head);
    deletePos(1, head);
    cout<<endl;
    print(head);
    deletePos(4, head);
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<isCircular(head);
return 0;
}