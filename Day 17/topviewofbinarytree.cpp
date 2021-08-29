#include <bits/stdc++.h>
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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
map<Node* , int> dist;
void travel(Node* root, int n)
{
    if(root->left!=NULL)
    {
        dist[root->left]=n-1;
        travel(root->left,n-1);
    }
    if(root->right!=NULL)
    {
        dist[root->right]=n+1;
        travel(root->right,n+1);
    }
  return;
}
void topView(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }
    dist[root]=0;
    travel(root,0);
    map<int,int> view;
    queue<Node*> q;
    view[0]=root->data;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        if(curr->left!=NULL)
        {
            int k = dist[curr->left];
            if(view.count(k)==0)
            {
                view[k]=curr->left->data;
            }
         q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            int k = dist[curr->right];
            if(view.count(k)==0)
            {
                view[k]=curr->right->data;
            }
         q.push(curr->right);
        }
    }
    for(auto i:view)
    {
        cout<<i.second<<" ";
    }
}
