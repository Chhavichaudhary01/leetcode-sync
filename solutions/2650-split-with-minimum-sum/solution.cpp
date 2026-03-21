class Solution {
public:
    int splitNum(int num) {
        vector<int>d;
        while(num>0){
            d.push_back(num%10);
            num/=10;
        }
        sort(d.begin(),d.end());
        int num1 =0, num2=0;
        for(int i =0;i< d.size();i++){
            if(i%2 ==0){
                num1 = num1*10+d[i];
                
            }
            else{
                num2 = num2*10+d[i];
            }
        }
        return num1 +num2;
    }
};
