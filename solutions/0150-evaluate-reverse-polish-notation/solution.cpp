class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string val : tokens) {

            if(val == "+") {
                int first = s.top(); s.pop();
                int second = s.top(); s.pop();

                s.push(second + first);
            }

            else if(val == "-") {
                int first = s.top(); s.pop();
                int second = s.top(); s.pop();

                s.push(second - first);
            }

            else if(val == "*") {
                int first = s.top(); s.pop();
                int second = s.top(); s.pop();

                s.push(second * first);
            }

            else if(val == "/") {
                int first = s.top(); s.pop();
                int second = s.top(); s.pop();

                s.push(second / first);
            }

            else {
                s.push(stoi(val));
            }
        }

        return s.top();
    }
};
