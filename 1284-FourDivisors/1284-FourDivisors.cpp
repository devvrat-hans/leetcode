// Last updated: 1/6/2026, 10:02:21 PM
class Solution {
public:
    bool hasFourDivisors(int num) {
        int cnt = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                cnt++;               
                if (i != num / i)
                    cnt++;          

                if (cnt > 4) return false;
            }
        }
        return cnt == 4;
    }

    int divisorSum(int n) {
        int summ = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                summ += i;
                if (i != n / i)
                    summ += n / i;
            }
        }
        return summ;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            if (hasFourDivisors(num)) {
                ans += divisorSum(num);
            }
        }
        return ans; 
    }
};
