#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

void insert_at_head(node* &head, int d)
{
 
    node* temp = new node(d);
    temp->next = head;
    head = temp; 
    return;

}

void insert_at_tail(node* &tail,int d)
{
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;    
}

void insertatpos(node* &head, node* &tail, int d, int position)
{
    node* node1 = head;
    if(position == 1)
    {
        insert_at_head(head, d);
    }
    int cnt = 1;
    node* temp = head;
    while(cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }
    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;

    if (temp->next ==NULL)
    {
        insert_at_tail(head, d);
        return ;
    }
}
void printLL(node* head)
{
    node* tm = head;
    while(tm != NULL)
    {
        cout<<tm->data<<" ";
        tm = tm->next;
    }
}
void deleteNode(node* &head, int pos)
{
    node* prev = NULL;
    node* curr = head;
    int cn=1;
    while(cn<pos)
    {
        prev = curr;
        curr=curr->next;
        cn++;
    }
    prev->next = curr->next ;
    delete curr;
}
void reverseLL(node* &head)
{
    node*prev = NULL;
    node* curr= head;
    while(curr!=NULL)
    {
        node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void recurReverseLL(node* head, node* curr, node* prev  )
{
        
    
    if(curr==NULL)
    {
        head = prev;
        return;
    }
    node* forward = curr->next;
    curr = head;
    curr ->next = prev;
    prev = curr;
    curr = forward;

}
int getlength(node* head)
{
    int cnt=0;
    while(head != NULL)
    {
        head = head -> next;
        cnt++;
    }
    return cnt;
}
node* findmidNode(node* head)
{
    node*temp = head;
    int len = getlength(head);
    int mid = len /2;
    while(mid--)
    {
        temp = temp->next;
    }
    return temp;
    
}
int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    // node* head = NULL;
    insert_at_head(head,91);
    insert_at_head(head,03);
    printLL(head);
    cout<<endl;
    
    //insert at tail;
    insert_at_tail(tail,82);
    insert_at_tail(tail, 23);
    insert_at_tail(tail, 87);
    printLL(head);
    cout<<endl;

    insertatpos(head, tail, 22, 4);
    printLL(head);
    cout<<endl;
    cout<<"the middle node of the LL is : "<<endl;
    cout<<findmidNode(head)->data<<endl;
    
    cout<<endl;
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    cout<<endl;
    deleteNode(head, 2);
    printLL(head);
    reverseLL(head);
    cout<<endl;
    printLL(head);
    cout<<endl;
    recurReverseLL(head, NULL, head);
    printLL(head);
    return 0;
}