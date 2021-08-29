//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];

		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int start=0;
unordered_map<int,int> ump;
Node *buildtreehelper(int in[], int pre[], int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = ump[pre[start]];
    Node* root = new Node(pre[start]);
    start++;
    root->left = buildtreehelper(in,pre,s,mid-1);
    root->right = buildtreehelper(in,pre,mid+1,e);
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
  start=0;
  for(int i=0;i<n;i++)
  {
      ump[in[i]]=i;
  }
  return buildtreehelper(in,pre,0,n-1);
}
