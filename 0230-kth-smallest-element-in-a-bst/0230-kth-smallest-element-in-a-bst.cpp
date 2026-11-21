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
    void traverse(TreeNode* root,priority_queue<int, vector<int>, greater<int>>& pq){
        if(root == NULL) return;

        traverse(root->left, pq);
        pq.push(root->val);
        traverse(root->right, pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        traverse(root, pq);
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};