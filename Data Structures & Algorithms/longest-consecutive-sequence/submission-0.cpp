class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;  // handle empty case

        sort(nums.begin(), nums.end());
        int res = 1;
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                // skip duplicates
                continue;
            }
            else if(nums[i] == nums[i-1] + 1) {
                count++;   // consecutive element
            }
            else {
                count = 1; // reset streak
            }
            res = max(res, count);
        }
        return res;
    }
};
