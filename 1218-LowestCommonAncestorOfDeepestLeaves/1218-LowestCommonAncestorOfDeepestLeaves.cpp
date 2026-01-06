// Last updated: 1/6/2026, 10:02:25 PM
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
    // Helper function returns a pair of (LCA of deepest leaves, maximum depth)
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};  // Base case
        
        // Recursively process left and right children.
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        // Compare depths from left and right.
        if (left.second == right.second)
            return {node, left.second + 1};  // Current node is the LCA.
        else if (left.second > right.second)
            return {left.first, left.second + 1};  // Left subtree is deeper.
        else
            return {right.first, right.second + 1};  // Right subtree is deeper.
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
