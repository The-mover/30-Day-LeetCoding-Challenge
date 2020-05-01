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
    bool rec(TreeNode* root, int index, vector<int>& arr) {
        if( !root ) return false;
        if( index == arr.size() ) return false;
        if( root->val != arr[index] ) return false;
        if( !root->right && !root->left && index == arr.size() - 1 && arr[index] == root->val ) return true;
        return rec(root->left, index+1, arr) | rec(root->right, index+1, arr);
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if( !root ) return false;
        return rec(root, 0, arr);
    }
};