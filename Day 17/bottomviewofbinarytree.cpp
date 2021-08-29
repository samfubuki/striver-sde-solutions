#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
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
void helper(vector<int> &v, Node *root)
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
            view[k]=curr->left->data;
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            int k = dist[curr->right];
            view[k]=curr->right->data;
            q.push(curr->right);
        }
    }
    for(auto i:view)
    {
        v.push_back(i.second);
    }
}
vector <int> bottomView(Node *root)
{
   vector<int> v;
   helper(v,root);
   return v;
}
