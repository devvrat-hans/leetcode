// Last updated: 1/6/2026, 10:01:15 PM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n+1, 0), res(n);
        int cnt = 0;

        for(int i = 0; i<n; i++){

            freq[A[i]]++;
            if(freq[A[i]] == 2) cnt += 1;

            freq[B[i]]++;
            if(freq[B[i]] == 2) cnt += 1;

            res[i] += cnt;

        }

        return res;
    }
};
