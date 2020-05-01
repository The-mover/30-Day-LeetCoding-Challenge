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
    int ans = 0;
    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        ans = max(ans, L+R+1);
        return max(L, R) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if( root == NULL ) return 0;
        dfs(root);
        return ans - 1;
    }
};