/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if ((root->left && root->left->val != root->val) || (root->right && root->right->val != root->val))
            return false;
        return isUnivalTree(root->left) & isUnivalTree(root->right);
    }
};