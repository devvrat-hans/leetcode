// Last updated: 1/6/2026, 10:01:20 PM
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {

        long long low = 0;
        long long high = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * (long long)cars;
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long total_cars = 0;
            for (int rank : ranks) {
                total_cars += (long long)floor(sqrt((long double)mid / rank));
                if (total_cars >= cars)
                    break;
            }
            if (total_cars >= cars)
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};
