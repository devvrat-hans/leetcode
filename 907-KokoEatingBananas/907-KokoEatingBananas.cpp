// Last updated: 1/6/2026, 10:02:34 PM
class Solution {
public:
    int helper(vector<int> piles, int k){
        int cnt = 0;

        for(int i = 0; i<piles.size(); i++){
            cnt += ceil((double)piles[i]/k);
        }

        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        if(n>h) return -1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(helper(piles, mid) <= h){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};