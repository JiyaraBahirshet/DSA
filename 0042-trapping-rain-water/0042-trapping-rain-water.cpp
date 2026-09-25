class Solution {
public:
    int trap(vector<int>& height) {
        int LMax=0;
        int RMax=0;
        int total=0;
        int l=0;
        int r=height.size()-1;

        while(l<r){
            if(height[l]<=height[r]){
                if(LMax>height[l]){
                    total+=LMax-height[l];
                }
                else{
                    LMax=height[l];
                }
                l=l+1;
            }
            else{
                if(RMax>height[r]){
                    total+=RMax-height[r];
                }
                else{
                    RMax=height[r];
                }
                r=r-1;
            }
        }
        return total;
        
    }
};