// Last updated: 1/9/2026, 10:08:00 PM
class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProductVal = 0;

    long long computeTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + computeTotal(root->left) + computeTotal(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long subSum = left + right + root->val;

        // calculate product if we split here
        long long product = subSum * (totalSum - subSum);
        maxProductVal = max(maxProductVal, product);

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = computeTotal(root);
        dfs(root);
        return maxProductVal % MOD;
    }
};
