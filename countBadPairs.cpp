#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;  // Total pairs
        
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int transformedValue = nums[i] - i;
            if (freq.find(transformedValue) != freq.end()) {
                goodPairs += freq[transformedValue]; // Adding already seen counts
            }
            freq[transformedValue]++; // Increase frequency
        }
        
        return totalPairs - goodPairs;
    }
};
