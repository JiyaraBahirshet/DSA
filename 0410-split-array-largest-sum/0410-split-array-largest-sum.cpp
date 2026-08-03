class Solution {
public:
    int countSubarrays(vector<int>& nums,int maxSum){
        int count=1;
        long long sum=0;
        for(int num:nums){
            if(sum+num<=maxSum){
                sum+=num;
            }
            else{
                count++;
                sum=num;
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        long long high=0;
        for(int num:nums){
            high+=num;
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            int subArrays=countSubarrays(nums,mid);
            if(subArrays<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};