// Last updated: 1/6/2026, 10:01:07 PM
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modExp(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    vector<int> primeFactorCount(int maxNum) {
        vector<int> spf(maxNum + 1, 0);  
        for (int i = 2; i <= maxNum; ++i) {
            if (spf[i] == 0) { 
                for (int j = i; j <= maxNum; j += i) {
                    spf[j]++;
                }
            }
        }
        return spf;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores = primeFactorCount(100000);
        vector<int> score(n);
        
        for (int i = 0; i < n; i++) {
            score[i] = primeScores[nums[i]];
        }
        
        vector<int> left(n), right(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[st.top()] < score[i]) {
                st.pop();
            }
            left[i] = (st.empty() ? i + 1 : i - st.top());
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[st.top()] <= score[i]) {
                st.pop();
            }
            right[i] = (st.empty() ? n - i : st.top() - i);
            st.push(i);
        }
        
        vector<pair<int, long long>> elements;
        for (int i = 0; i < n; i++) {
            long long contribution = (long long)left[i] * right[i];
            elements.push_back({nums[i], contribution});
        }
        
        sort(elements.rbegin(), elements.rend());
        
        long long result = 1;
        for (auto& [value, count] : elements) {
            if (k <= 0) break;
            long long take = min((long long)k, count);
            result = (result * modExp(value, take)) % MOD;
            k -= take;
        }
        
        return result;
    }
};
