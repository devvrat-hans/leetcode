// Last updated: 1/6/2026, 10:01:04 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        
        // Precompute right-side information.
        // rightPos[i] = maximum positive value among nums[i+1...n-1] (or -1 if none)
        // rightNeg[i] = minimum negative value among nums[i+1...n-1] (or 1 if none)
        vector<long long> rightPos(n, -1);
        vector<long long> rightNeg(n, 1);
        // For the last index, no candidate exists.
        rightPos[n-1] = -1;
        rightNeg[n-1] = 1;
        
        for(int i = n - 2; i >= 0; i--) {
            int candidate = nums[i + 1];
            // For positive candidate
            if(candidate > 0) {
                rightPos[i] = max((long long)candidate, rightPos[i+1]);
            } else {
                rightPos[i] = rightPos[i+1];
            }
            // For negative candidate
            if(candidate < 0) {
                // If we already have a negative candidate on the right, take the smaller one (more negative)
                if(rightNeg[i+1] < 0)
                    rightNeg[i] = min((long long)candidate, rightNeg[i+1]);
                else 
                    rightNeg[i] = candidate;
            } else {
                rightNeg[i] = rightNeg[i+1];
            }
        }
        
        long long ans = 0;
        long long leftMax = nums[0];
        long long leftMin = nums[0];
        
        // Iterate over j (middle index) from 1 to n - 2
        for(int j = 1; j < n - 1; j++){
            // Update leftMax and leftMin from indices [0, j-1]
            leftMax = max(leftMax, (long long)nums[j-1]);
            leftMin = min(leftMin, (long long)nums[j-1]);
            
            long long candidate1 = 0, candidate2 = 0;
            
            // Case 1: using a positive right candidate
            if(rightPos[j] > 0 && leftMax > nums[j]) {
                candidate1 = (leftMax - nums[j]) * rightPos[j];
            }
            // Case 2: using a negative right candidate
            if(rightNeg[j] < 0 && leftMin < nums[j]) {
                candidate2 = (leftMin - nums[j]) * rightNeg[j];
            }
            
            ans = max(ans, max(candidate1, candidate2));
        }
        
        return ans;
    }
};
