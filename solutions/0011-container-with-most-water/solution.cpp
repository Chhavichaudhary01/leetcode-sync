class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater =0;
        int w , h,area;
        int lp = 0, rp = height.size() - 1;
        while(lp <rp){
            w = rp - lp;
            h = min(height[lp], height[rp]);
            area = w * h;
            maxWater = max(maxWater, area);
            height[lp]<height[rp]? lp++ : rp--;
        }
       return maxWater;
    }
};
