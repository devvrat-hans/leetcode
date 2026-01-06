// Last updated: 1/6/2026, 10:02:03 PM
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> arr;  
        vector<int> res(n,0);  

        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                arr.emplace_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr.size(); j++) {
                res[i] += abs(arr[j] - i);
            }
        }

        return res;
    }
};
