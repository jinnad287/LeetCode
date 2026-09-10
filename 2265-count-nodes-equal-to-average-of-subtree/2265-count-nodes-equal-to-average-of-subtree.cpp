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
    using P = pair<int, int>; // pair<int, int> ---> {count, sum}

    P solve(TreeNode* root, int& ans){
        if(root == NULL) return {0, 0};

        P left_pair = solve(root->left, ans);
        P right_pair = solve(root->right, ans);

        int curr_sum = left_pair.second + root->val + right_pair.second;
        int nodes = left_pair.first + 1 + right_pair.first;
        if(curr_sum/nodes == root->val){
            ans++;
        }

        return {nodes, curr_sum};

    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);

        return ans;
    }
};