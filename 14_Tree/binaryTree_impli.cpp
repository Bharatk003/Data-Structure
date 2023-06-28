#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};
void reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        s.push(temp);
        
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        
    }
    vector<int > n;
    while(!s.empty())
    {
        Node*temp = s.top();
       
        
        cout<<temp->data<<" ";
        s.pop();
    }

}


Node * BuildfromlevelOrder(Node *&root)
{
	queue<Node*> q;	
	cout<<"enter the data: "<<endl;
	int data;
	cin>> data;
	root = new Node(data);
	q.push(root);
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		cout<<"enter left node for"<<temp->data<<endl;
		int leftData;
		cin>>leftData;
		
		if(leftData != -1)
		{
			temp->left = new Node(leftData);
			q.push(temp->left);	
	   }
	   
	   cout<<"enter right node for"<<temp->data<<endl;
		int rightData;
		cin>>rightData;
		
		if(rightData != -1)
		{
			temp->right = new Node(rightData);
			q.push(temp->right);	
	   }
	}
	 ;
	
}

Node* buildTree(Node* root )
{
    cout<<" enter the data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1 )
    {
        return NULL;
    }
    cout<<endl<<"Enter the left of the "<<data ;
    root->left = buildTree(root->left);
    cout<<endl;
    cout<<endl<<"enter the right of the "<<data;
    root->right = buildTree(root->right);

    return root;

	 }

void inorder(Node* root)
{
	if(root ==  NULL)
	{
		return ;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
}



void postorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	postorder( root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}



void levelOrderedTraversal(Node* root)
{
   queue<Node*>q;
   q.push(root);
   cout<<endl;
   while(!q.empty())
   {	
   	Node*temp = q.front();
   	cout<<temp->data<<" ";
   	q.pop();
   	
   	if(temp->left)
   	{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);		
		}
   	
	}  
}

int hightoftree(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = hightoftree(root->left);
    int right = hightoftree(root->right);

    int ans = max(left, right)+1;
    return ans;
}
int main()
{
    Node* root = NULL;
    //build tree
   // root = buildTree(root);
   // levelOrderedTraversal(root);
    //cout<<endl;
   // reverseLevelOrder(root);
    
   // cout<<endl<<"inorder Travesal: "<<endl;
    //inorder(root);
    
    ///cout<<endl<<"preorder Traversal: "<<endl;
   // preorder(root);
    
   // cout<<endl<<"postorder Traversal: "<<endl;
   // /postorder(root);
 	BuildfromlevelOrder(root);
 	levelOrderedTraversal(root);
 	cout<<"the height of the tree is : "<<hightoftree(root);

return 0;
}
