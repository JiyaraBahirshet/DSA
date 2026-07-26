class Solution {
public:

    bool canMake(vector<int>& bloomDay,int day,int m,int k){
        int flowers=0;
        int bouquets=0;

        for(int bloom: bloomDay){
            if(bloom<=day){
                flowers++;
            }
            else{
                bouquets+=flowers/k;
                flowers=0;
            }
        }
        bouquets+=flowers/k;
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers=1LL*m*k;
        if(totalFlowers>bloomDay.size()){
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canMake(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};