// Last updated: 1/6/2026, 10:01:25 PM
class Solution {
public:
    bool isprime(int n) {
        if (n < 2) return false;  
        if (n == 2) return true;  
        if (n % 2 == 0) return false;
        
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for (int i = left; i <= right; i++) {
            if (isprime(i)) primes.push_back(i);
        }

        if (primes.size() < 2) return {-1, -1};  

        int mini = INT_MAX;
        int prev = -1;

        for (int i = 0; i < primes.size() - 1; i++) {
            if (primes[i + 1] - primes[i] < mini) {
                mini = primes[i + 1] - primes[i];
                prev = i;
            }
        }

        return {primes[prev], primes[prev + 1]};
    }
};
