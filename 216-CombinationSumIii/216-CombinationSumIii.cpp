// Last updated: 3/27/2026, 5:27:07 PM
class Solution {
public:
    void func(int ind, int k, int currSum, int n, vector<int>& ds, vector<vector<int>>& ans) {

        if (ds.size() == k) {
            if (currSum == n)
                ans.push_back(ds);
            return;
        }

        if (ind > 9 || currSum > n) return;

        ds.push_back(ind);
        func(ind + 1, k, currSum + ind, n, ds, ans);
        
        ds.pop_back();
        func(ind + 1, k, currSum, n, ds, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        func(1, k, 0, n, ds, ans);
        return ans;
    }
};
