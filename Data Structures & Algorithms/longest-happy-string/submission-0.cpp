class Solution {
public:
    typedef pair<int,char> P;

    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq;

        if(a > 0){
            pq.push({a,'a'});
        }
        if(b > 0){
            pq.push({b,'b'});
        }
        if(c > 0){
            pq.push({c,'c'});
        }

        string ans = "";

        while(!pq.empty()){

            int currcount = pq.top().first;
            char currchar = pq.top().second;
            pq.pop();

            // 3 same characters nahi aane chahiye
            if(ans.length() >= 2 &&
               ans[ans.length()-1] == currchar &&
               ans[ans.length()-2] == currchar){

                // next largest character chahiye
                if(pq.empty()){
                    break;
                }

                int nextcount = pq.top().first;
                char nextchar = pq.top().second;
                pq.pop();

                // next character use karo
                ans.push_back(nextchar);
                nextcount--;

                if(nextcount > 0){
                    pq.push({nextcount,nextchar});
                }

                // current character ko wapas heap mein daalo
                pq.push({currcount,currchar});

            }
            else{

                // current largest character use karo
                ans.push_back(currchar);
                currcount--;

                if(currcount > 0){
                    pq.push({currcount,currchar});
                }
            }
        }

        return ans;
    }
};