class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
         stack<pair<int,int>> st; 
         vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int temp=1;
            while(!st.empty() && st.top().first<=nums[i]){
                temp+=st.top().second;
                st.pop();
            }
            
            if(st.empty())
                ans[i] = 0;
            else
                ans[i] = temp;
        
        st.push({nums[i],temp});
        }
        return ans;
    }
};
