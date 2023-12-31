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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;
        while(!stack.empty() || root)
        {
            while(root)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(root-> val <= inorder)
                return false;
            inorder = root->val;
            root = root->right;
        }
        return 1;
    }
};