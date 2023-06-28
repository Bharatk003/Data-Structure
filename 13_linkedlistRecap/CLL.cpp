#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~node()
    {
        if(this->next != NULL)
        {
            delete next;
            next  = NULL;
        }
    }
};

void insertNode(node* &tail,int val, int d)
{
    //empty list
    if(tail == NULL)
    {
        node* newNode = new node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    // non empty list
    else
    {
        node* curr = tail;
        while(curr->data != val)
        {
            curr=curr->next;
        }
        node* forword = curr->next; //circuler pointer pointing to the 
        node* temp = new node(d);
        curr->next = temp;
        temp->next = forword;

    }

}

void deleteLL(node* &tail, int val)
{
    if(tail == NULL)
    {
        cout<<"There is no linkded list present: "<<endl;
        return;
    }
    node* prev = tail;
    node*curr = prev->next;
    while(curr->data != val)
    {
        prev = curr;
        curr=curr->next;
    }
    prev ->next = curr->next;
    if(curr == prev)
    {
        tail = NULL;
    }
    if(tail == curr)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}
void printLL(node* tail)
{
    cout<<tail->data<<" ";
    node* temp = tail->next;
     
    while(temp != tail)
    {
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
}
int main()
{
    node* tail = NULL;
    insertNode(tail, 5 ,3);
    insertNode(tail, 3, 9);
    insertNode(tail, 9, 12);
    printLL(tail);
    cout<<endl;
    insertNode(tail, 9,8);
    printLL(tail);
    insertNode(tail, 3, 4);
    cout<<endl;
    printLL(tail);
    cout<<endl;
    deleteLL(tail, 4);
    deleteLL(tail,3);
    deleteLL(tail,8);
    deleteLL(tail,12);
    deleteLL(tail, 9);
    printLL(tail);
    
return 0;
}