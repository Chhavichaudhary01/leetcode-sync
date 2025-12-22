class Solution {
public:
    int climbStairs(int n) {
        
        int prev =1;
        int next =2;
        int curr;
        if(n==1)return 1;
        if(n==2)return 2;
        for(int i =3;i<=n;i++){
            curr = prev + next;
            prev= next;
            next = curr;
        }

        return next;

       
    }
    
};
