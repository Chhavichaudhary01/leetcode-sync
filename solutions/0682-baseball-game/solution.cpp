class Solution {
public:
    int calPoints(vector<string>& ops) {
        int result=0;
        stack<int>s;
       for(string op: ops){
        if(op == "C"){
            s.pop();
        }else if( op == "D"){
            s.push(2* s.top());
        }else if ( op == "+"){
            int first = s.top();
            s.pop();
            int second = s.top();
            s.push(first);
            s.push(first+second);
        }else{
            s.push(stoi(op));
        }
       }
       while(!s.empty()){
        result += s.top();
        s.pop();
       }
       return result;
    }
};
