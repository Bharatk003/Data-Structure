#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL; 
    }

    ~node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }

    }
};

void insertathead(node* &head, int d)
{ 
    node* temp = head;
    node* newNode = new node(d);
    newNode->next =  temp;
    temp -> prev = newNode;
    head = newNode;
}

void insertattail(node *&tail, int d)
{
    node* temp = tail;
    node* newNode = new node(d);
    newNode->prev = temp;
    temp->next = newNode;
    tail = newNode;


}

void insertatval(node* &head, node* &tail,int val,  int d)
{
    if(val == head->data)
    {
        insertathead(head, d);
        return;
    }

    node* curr = head;
    node*temp = head;
    while(val != temp->data)
    {
        temp = temp->next;
        if(temp->next==NULL)
        {
            cout<<"the val not exit!!"<<endl;
            return;
        }
    }

    node* newNode = new node(d);
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;

}
void deleteLL(node* &head, int val)
{
    node* temp = head;
    node* prevs;
    node* curr = temp;
    if(head->data == val)
    {
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
        return;
    }
    while(curr->data != val)
    {
        prevs = curr;
        curr = curr->next;
    }
    curr->prev = NULL;
     
    prevs -> next = curr->next;
    curr->next->prev = prevs;
    curr->next = NULL; 
    delete curr;
 
}
void printLL(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 3);
    insertathead(head, 2);
    insertathead(head, 1);
    printLL(head);
    cout<<endl;
    insertattail(tail, 98);
    printLL(head);
    cout<<endl;
    insertatval(head, tail, 3, 773);
    printLL(head);
    cout<<endl;
    deleteLL(head, 773);
    deleteLL(head, 10);
    deleteLL(head,1);
    deleteLL(head,2);
    deleteLL(head,3);
    deleteLL(head,4);   
    deleteLL(head,5);

    printLL(head);
    

    
   
return 0;
}