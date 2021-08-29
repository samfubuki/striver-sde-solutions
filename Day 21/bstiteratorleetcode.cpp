/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    queue<int> q;
public:
    void helper(TreeNode* node)
    {
        if(node==NULL)
        {
            return;
        }
        else
        {
            if(node->left!=NULL)
            {
                helper(node->left);
            }
            q.push(node->val);
            if(node->right!=NULL)
            {
                helper(node->right);
            }
        }
    }
    BSTIterator(TreeNode* root) {
        helper(root);
    }

    int next() {
       int temp = q.front();
       q.pop();
       return temp;
    }

    bool hasNext() {
        if(q.empty())
        {
            return false;
        }
      return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
