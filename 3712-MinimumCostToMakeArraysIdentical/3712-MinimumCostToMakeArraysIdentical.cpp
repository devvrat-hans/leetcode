// Last updated: 1/6/2026, 10:00:29 PM
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        bool eq = true;
        int m = arr.size();
        int n = brr.size();

        for(int i = 0; i<n; i++){
            if(arr[i] != brr[i]){
                eq = false;
                break;
            }
        }

        if(eq == true) return 0;

        long long cost_wout = 0;
        for(int j = 0; j < n; j++){
            cost_wout += abs(arr[j] - brr[j]);
        }

        long long cost_with = k;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for(int k = 0;k<n; k++){
            cost_with += abs(arr[k] - brr[k]);
        }

        return min(cost_with, cost_wout);

        
        
    }
};