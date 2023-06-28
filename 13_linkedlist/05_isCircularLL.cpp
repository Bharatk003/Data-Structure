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
        int val = this->data;
        if(this->next != NULL) 
        {
            delete next;
            next = NULL;
        }
        cout<<"deleting the element: "<<val<<endl;
    }
};

bool isCircular(node *head)
{
    node* temp = head->next;
    
    if(temp == NULL );
    {    
        return true;
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
void insertnode(node *&tail, int element, int d)
{
    //for empty list
    if(tail == NULL)
    {
        node* newNode = new node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        //non empty list: 
        // assuming that at least one element is present
        node *curr = tail ;
        while(curr->data != element)
        {
            curr = curr -> next;
        }
        
        node* newNode = new node(d);
        newNode->next = curr->next;
        curr->next = newNode;
        
    }
}

void printnode(node *tail)
{
    node* temp = tail;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);

    cout<<endl;
}

// void deletenode(node *&tail, int element)
// {
//     if(tail == NULL)
//     {
//         cout<<"Linked List is not exist: "<<endl;
//     }
//     else
//     {
         
//         node *prev = tail;
//         node *curr = prev->next;
//         while(curr->data != element)
//         {
//             prev = curr;
//             curr = curr->next;
//         }
//         prev->next = curr->next;

//         //one node linked list deletion
//         if(curr == prev)
//         {
//             tail=NULL;
//         }
//         if(tail == curr)
//         {
//             tail = prev->next;
//         }
//         curr->next=NULL;
//         delete curr;
//     }
// }
int main()
{  
    node*tail = NULL;
    
    insertnode(tail, 0, 12);
    printnode(tail);

    insertnode(tail, 12, 3);
    printnode(tail);
    
    insertnode(tail, 3, 5);
    printnode(tail);

    insertnode(tail, 5, 7);
    printnode(tail);

    insertnode(tail, 7, 9);
    printnode(tail);

    insertnode(tail, 12, 2);
    printnode(tail);

    insertnode(tail, 3, 4);
    printnode(tail);

    insertnode(tail, 5, 6);
    printnode(tail);   

    insertnode(tail, 7, 8);
    printnode(tail);

    cout<<isCircular(tail);
    // deletenode(tail, 12);    
    // printnode(tail);
return 0;
}
