// Last updated: 3/27/2026, 5:27:10 PM
class Solution {
public:
    vector<int> preCompute(int n){
        vector<int> prime(n, 1); 

        if (n > 0) prime[0] = 0;
        if (n > 1) prime[1] = 0;

        for(int i = 2; i*i < n; i++){
            if(prime[i]){
                for(int j = i*i; j<n; j+=i){
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }

    int countPrimes(int n) {
        vector<int> prime = preCompute(n);

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};
