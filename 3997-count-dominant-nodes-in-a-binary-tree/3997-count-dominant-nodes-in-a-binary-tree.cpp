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
    int ans = 0;

    int dfs(TreeNode* root){
        if(!root) return INT_MIN;

        int leftmax = dfs(root->left);
        int rightmax = dfs(root->right);

        int mx = max({root->val, leftmax, rightmax});

        if(root->val == mx) ans++;

        return mx;
    }

    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};