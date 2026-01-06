// Last updated: 1/6/2026, 10:01:29 PM
class Solution {
public:
    int bestClosingTime(string customers) {
        int maxIndex = 0, maxSum = -2, n = customers.size();
        int cnt = 0;

        for(int i  = 0; i<n; i++){
            if(customers[i] == 'Y'){
                cnt++;
                if(cnt > maxSum){
                    maxSum = cnt;
                    maxIndex = i;
                }
            }
            else cnt--;
        }

        return maxSum > 0 ? maxIndex+1 : 0;

    }
};