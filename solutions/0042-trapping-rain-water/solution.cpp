class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // vector<int>lMax(n,0);
        // vector<int>rMax(n,0);
        // int ans =0;

        // lMax[0] = height[0];
        // rMax[n-1] = height[n-1];

        // for(int i =1;i<n;i++){
        //     lMax[i] = max(lMax[i-1],height[i]);
        // }

        // for(int i = n-2;i>=0;i--){
        //     rMax[i] = max(rMax[i+1],height[i]);


        // }

        // for(int i = 0;i<n;i++){
        //     ans += min(lMax[i], rMax[i]) - height[i];

        // }

        // return ans; 




        /////*******MORE OPTIMAL {TWO POINTER APPROACH}
        int n = height.size();
        int l = 0, r = n-1;
        int ans = 0;
        int lmax = 0, rmax = 0;

        while(l<r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax, height[r]);

            if(lmax<rmax){
                ans+= lmax- height[l];
                l++;
            }else{
                ans+= rmax - height[r];
                r--;
            }
        }
        return ans;

        

        
        
    }
};
