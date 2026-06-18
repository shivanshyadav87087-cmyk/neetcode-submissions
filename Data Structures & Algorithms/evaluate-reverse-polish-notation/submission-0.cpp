class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<int> st;

        for(string tokens : token) {

            if(tokens == "+" || tokens == "-" || 
               tokens == "*" || tokens == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(tokens == "+") st.push(a + b);
                else if(tokens == "-") st.push(a - b);
                else if(tokens == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                st.push(stoi(tokens));
            }
        }

        return st.top();
    }
};