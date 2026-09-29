class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> f;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            f[nums[i]]++;
        }
        
        for(auto it : f) {
            if(it.second > n/3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};