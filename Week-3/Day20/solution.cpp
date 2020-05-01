/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *helper(TreeNode *root, int val) {
        if( root == NULL ) {
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        if( val < root->val ) {
            root->left = helper(root->left, val);
        } else {
            root->right = helper(root->right, val);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if( n == 0 ) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        for(int i=1; i<n; i++) {
            helper(root, preorder[i]);
        }
        return root;
    }
};