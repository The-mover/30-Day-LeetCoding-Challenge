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
private:
    int mx = -1e9 + 5;
    int rec(TreeNode *root) {
        //cout << "root = " << root->val << endl;
        if( root == NULL ) return 0;
        int L = rec(root->left);
        int R = rec(root->right);
        int sum = root->val + max(L, 0) + max(R, 0);
        mx = max(mx, sum);
        sum = root->val + max(0, max(L, R));
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        if( root == NULL ) return 0;
        rec(root);
        return mx;
    }
};