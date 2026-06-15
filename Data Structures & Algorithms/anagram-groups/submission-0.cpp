class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string, vector<string>> f;  

        for(int i = 0; i < n; i++) {
            string temp = nums[i];
            sort(temp.begin(), temp.end());        
            f[temp].push_back(nums[i]);            
        }

        vector<vector<string>> res;               
        for(auto &it : f) {
            res.push_back(it.second);
        }
        return res;
    }
};
