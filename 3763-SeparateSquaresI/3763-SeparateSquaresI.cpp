// Last updated: 1/22/2026, 5:43:09 PM
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        auto diff = [&](double H) {
            long double res = 0;
            for (auto &s : squares) {
                long double y = s[1];
                long double l = s[2];

                long double below = min(max(H - y, 0.0L), l);
                long double total = l * l;

                res += 2 * below * l - total;
            }
            return res;
        };

        for (int i = 0; i < 80; i++) { // sufficient for 1e-5
            double mid = (low + high) / 2.0;
            if (diff(mid) < 0)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
