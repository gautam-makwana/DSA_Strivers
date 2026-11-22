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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        int l=1;
        vector<long long> arr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           int s = size(q);
           long long temp=0;
           for(int i=0;i<s;i++){
            TreeNode* curr = q.front();
            q.pop();
            temp+=curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
           }
           arr.push_back(temp);
        }
        if(arr.size() < k) return -1;
        sort(arr.begin(),arr.end());
        return arr[arr.size()-k];
    }
};