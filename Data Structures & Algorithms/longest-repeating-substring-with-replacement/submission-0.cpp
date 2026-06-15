int find(vector<int> &a)
{
    int maxc = -1;
    for(int i = 0; i < 256; i++)
    {
        maxc = max(maxc, a[i]);
    }
    return maxc;
}

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        vector<int> f(256,0);

        int low = 0;
        int high = 0;
        int res = 0;

        for(high = 0; high < n; high++)
        {
            f[s[high]]++;

            int len = high - low + 1;

            int maxcount = find(f);

            int diff = len - maxcount;

            while(diff > k)
            {
                f[s[low]]--;
                low++;

                maxcount = find(f);

                len = high - low + 1;
                diff = len - maxcount;
            }

            len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};