#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stack>
#include<queue>
#include<map>

using namespace std;


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void printPreorder(struct node *root)
{
	if(root)
	{
		cout<< root->data;
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printInorder(struct node *root)
{
	if(root)
	{
		printInorder(root->left);
		cout<< root->data;
		printInorder(root->right);
	}
}

void printPostorder(struct node *root)
{
	if(root)
	{
		printPostorder(root->left);
		printPostorder(root->right);
		cout<< root->data;
	}
}

struct node* newNode(int data)
{
     struct node* node = (struct node*)
     malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}

void printPreorderIter(struct node *root)
{
	stack<node *> nodeStack;
	while(1)
	{
		while(root)
		{
			cout<<root->data<< " " ;
			nodeStack.push(root);
			root = root->left;
		}
		
		if(nodeStack.empty()) break;
		
		root = nodeStack.top();
		nodeStack.pop();
		root = root->right;
	}
}

void printInorderIter(struct node *root)
{
	stack<node *> stk;
	while(1)
	{
		while(root)
		{
			stk.push(root);
			root = root->left;
		}
		
		if(stk.empty()) break;
		
		root = stk.top();
		cout<< root->data <<" ";
		
		stk.pop();
		root = root->right;
	}
}

void printPostorderIter(struct node *root)
{
	stack <node *> S;
	struct node * prev = NULL;
	do{
		while(root)
		{
			S.push(root);
			root = root->left;
		}
		while(root == NULL && !S.empty())
		{
			root = S.top();
			if(root->right == NULL || root->right == prev)
			{
				cout<<root->data <<" ";
				prev = root;
				S.pop();
				root = NULL;
			}
			else
				root = root->right;
		}
	} while(!S.empty());
}

void printLevelOrder(struct node* root)
{
	queue<node *>Q;
	if(!root) return;
	struct node* temp;
	Q.push(root);
	
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(temp) cout<<temp->data<<" ";		
		if(temp) 
		{
			Q.push(temp->left);
			Q.push(temp->right);
		}
	}
}

int FindMax(struct node* root)
{
	int max,root_val,left,right;
	
	if(root)
	{
		root_val = root->data;
		left = FindMax(root->left);
		right = FindMax(root->right);
		
		if(left > right)
		{
			max = left;
		}
		else max = right;
		
		if(root_val > max)
		{
			max = root_val;
		}
	}
	
	return max;	
}

int IterFindMax(struct node* root)
{
	queue<node *> q;
	if(!root) return 0;
	int max = 0;
	struct node * temp;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp)
		{
			if(temp->data > max) max = temp->data;
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return max;
}

int FindRecursion(struct node* root, int data)
{
	int temp = 0;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		if(root->data == data)
		{
			return 1;
		}
		else
		{
			temp = FindRecursion(root->left,data);
			if(temp) return 1;
			temp = FindRecursion(root->right,data);
		}
	}
	return temp;
}

int FindIterative(struct node* root, int data)
{
	struct node* temp;
	queue<node *>qu;
	if(!root) return 0;
	
	qu.push(root);
	while(!qu.empty())
	{
		temp = qu.front();
		
		qu.pop();
		if(temp)
		{
			if(temp->data == data) return 1;
			qu.push(temp->left);
			qu.push(temp->right);
		}
	}
	return 0;
}

int findSize(struct node* root)
{
	if(root == NULL) return 0;
	
	return findSize(root->left)+1+findSize(root->right);
}

void printRevLevelOrder(struct node* root)
{
	if(!root) return;
	struct node *temp;
	stack <node *> stk;
	queue <node *> que;
	
	que.push(root);
	while(!que.empty())
	{
		temp = que.front();
		que.pop();
		if(temp->right) que.push(temp->right);
		if(temp->left) que.push(temp->left);
		
		stk.push(temp);
	}
	while(!stk.empty())
	{
		cout<<stk.top()->data <<" ";
		stk.pop();
	}
}

void DeleteBinTree(struct node* root)
{
	if(!root) return;
	
	DeleteBinTree(root->left);
	DeleteBinTree(root->right);
	free(root);
}

int getHeightTree(struct node* root)
{
	if(!root) return 0;
	struct node* temp;
	int count = 0;
	queue<node *> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(temp == NULL)
		{
			if(!Q.empty()) Q.push(NULL);
			count++;
		}
		else
		{
			if(temp->left) Q.push(temp->left);
			if(temp->right) Q.push(temp->right);
		}
	}
	return count;
}

int diameterOpt(struct node *root, int* height)
{

  int lh = 0, rh = 0;
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0;
  }
  
  ldiameter = diameterOpt(root->left, &lh);
  rdiameter = diameterOpt(root->right, &rh);
  
  *height = max(lh, rh) + 1;

  return max(lh + rh + 1, max(ldiameter, rdiameter));

/*

int diameter(struct node* root, &height)
{
int lh,rh=0;
int ldiam , rdiam= 0l
if(root==NULL) *height = 0;return 0;

ldiam = diameter(root->left,&lh);
rdiam = diameter(root->right,&rh);

*height = max(lh,rh)+1;

return max(lh+rh+1,max(ldiam,rdiam));
*/
}

struct node* createMirror(struct node* root)
{
	struct node* temp;
	
	if(root)
	{
		createMirror(root->left);
		createMirror(root->right);
		
		temp = root->left;
		root->left=root->right;
		root->right=temp;
	}
	return root;
}

int printAncestor(struct node* root,struct node* node1)
{
	if(!root) return 0;
	
	if(root->data == node1->data)
	{
		return 1;
	}
	
	if(printAncestor(root->left,node1) || printAncestor(root->right,node1))
	{
		cout<<root->data <<" ";
		return 1;
	}
	return 0;
}

void printZigZag(struct node* root)
{
	if(!root) return;
	stack<node*> stk1;
	stack<node*> stk2;
	
	struct node* temp;
	stk1.push(root);
	
	while(!stk1.empty() || !stk2.empty())
	{
		while(!stk1.empty())
		{
			temp = stk1.top();
			stk1.pop();
			cout<< temp->data <<" ";
			if(temp->left)stk2.push(temp->left);
			if(temp->right)stk2.push(temp->right);
		}
		
		while(!stk2.empty())
		{
			temp = stk2.top();
			stk2.pop();
			if(temp) cout<<temp->data <<" ";
			if(temp->right) stk1.push(temp->right);
			if(temp->left) stk1.push(temp->left);
		}
	}
}

void verticalSumUtil(struct node* root, int hd,
                     map<int, int> &Map)
{
    if (root == NULL) return;

    verticalSumUtil(root->left, hd-1, Map);
    Map[hd] += root->data;
    verticalSumUtil(root->right, hd+1, Map);
}
 
void verticalSum(struct node *root)
{
    map < int, int> Map;
    map < int, int> :: iterator it;
 
    verticalSumUtil(root, 0, Map);
    
    for (it = Map.begin(); it != Map.end(); ++it)
    {
        cout << it->first << ": "
             << it->second << endl;
    }
}

struct node2{
	struct node2* left;
	struct node2* right;
	struct node2* nextSib;
};

void FillNextSibling(struct node2* root)
{
	if(!root) return;
	struct node2* temp;
	queue<node2 *> q1;
	q1.push(root);
	q1.push(NULL);
	
	while(!q1.empty())
	{
		temp = q1.front();
		q1.pop();
		if(root == NULL)
		{
			if(!q1.empty())
			{
				q1.push(NULL);
			}
		}
		else
		{
			root->nextSib = q1.front();
			if(root->left) q1.push(root->left);
			if(root->right) q1.push(root->right);
		}
	}
}

int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(8); 
 	 root->right->left     = newNode(6);
//     root->right->right   = newNode(7);
     
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
	 cout<<endl;
	 
	 cout<<"Iterative PreOrder Traversal ";
	 printPreorderIter(root);
	 cout<<endl;
	 
	 cout<<"Iterative Inorder Traversal " ;
	 printInorderIter(root);
	 cout<<endl;
	 
	 cout<<"Iterative PostOrder Traversal ";
	 printPostorderIter(root);
	 cout<<endl;
	 
	 cout<< "Level Order Traversal ";
	 printLevelOrder(root);
	 cout<<endl;
	 
	 cout<<" Find Max Value Recursive ";
	 int findM = FindMax(root);
	 cout<< findM <<endl;
	 
	 cout<<" Find Max Value Iterative ";
	 int findM2 = IterFindMax(root);
	 cout<< findM2 <<endl;
	 
	 cout<<" Find element in binary tree Recursion ";
	 int found = FindRecursion(root,7);
	 cout<< found <<endl;
	 
	 cout<<" Find element in binary tree iteratively ";
	 int found2 = FindIterative(root,4);
	 cout<< found2 <<endl;
	 
	 cout<<"Find size of binary tree ";
	 int size = findSize(root);
	 cout<< size <<endl;
	 
	 cout<<"Reverse level order traversal ";
	 printRevLevelOrder(root);
	 cout<<endl;
	 
	 cout<<"Find Height of tree ";
	 int heightT = getHeightTree(root);
	 cout<< heightT << endl;
	 
	 cout<<"Diameter of tree ";
	 int height = 0;
	 int diameter = diameterOpt(root, &height);
	 cout<< diameter <<endl;
	 
	 struct node* temp;
	 cout<<" creating mirror of root ";
	 temp = createMirror(root);
	 printLevelOrder(temp);
	 cout<<endl;
	 
	 cout<<" Print Ancestors of node ";
	 printAncestor(root,root->left->right);
	 cout<<endl;
	 
	 cout<<" ZigZag printing of nodes ";
	 printZigZag(root);
	 cout<<endl;
	 
	 cout<<" Vertical Sum of tree " <<endl; //nt clear look youtube hastable solved
	 verticalSum(root);
	 cout<<endl;
	 
	 cout<<" FillNextSibling ";
//	 FillNextSibling(root2);
	 cout<<endl;
	 
     getchar();
     return 0;
}
