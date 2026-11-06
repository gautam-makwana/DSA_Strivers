/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> traverse(TreeNode* root, vector<int>& ans,int level) {
        if (root == NULL)
            return ans;
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        
        traverse(root->right, ans, level+1);
        traverse(root->left, ans, level+1);
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans, 0);
        return ans;
    }
};