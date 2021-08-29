#include <iostream>
#include <algorithm>
using namespace std;

// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }

    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }

    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to construct balanced BST from the given sorted array.
// Note that the root of the tree is passed by reference here
void convert(int keys[], int low, int high, Node* &root)
{
    // base case
    if (low > high) {
        return;
    }

    // find the middle element of the current range
    int mid = (low + high) / 2;

    // construct a new node from the middle element and assign it to the root
    root = newNode(keys[mid]);

    // left subtree of the root will be formed by keys less than middle element
    convert(keys, low, mid - 1, root->left);

    // right subtree of the root will be formed by keys more than the middle element
    convert(keys, mid + 1, high, root->right);
}

// Function to construct balanced BST from the given unsorted array
Node* convert(int keys[], int n)
{
    // sort the keys first
    sort(keys, keys + n);

    // construct a balanced BST
    Node* root = nullptr;
    convert(keys, 0, n - 1, root);

    // return root node of the tree
    return root;
}

int main()
{
    // input keys
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int n = sizeof(keys)/sizeof(keys[0]);

    // construct a balanced binary search tree
    Node* root = convert(keys, n);

    // print the keys in an inorder fashion
    inorder(root);

    return 0;
}
