// Last updated: 1/6/2026, 10:03:34 PM
class Solution {
public:
    vector<string> func(int n, string current = "", int open = 0, int close = 0) {
        vector<string> res;

        if (open == n && close == n) {
            res.push_back(current);
            return res;
        }

        if (open < n) {
            vector<string> left = func(n, current + '(', open + 1, close);
            res.insert(res.end(), left.begin(), left.end());
        }

        if (close < open) {
            vector<string> right = func(n, current + ')', open, close + 1);
            res.insert(res.end(), right.begin(), right.end());
        }

        return res;
    }
    vector<string> generateParenthesis(int n) {
        return func(n);
    }
};