class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int x:nums){
            st.insert(x);
        }
        int longest=0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int current=num;
                int cnt=1;
                while(st.find(current+1)!=st.end()){
                    current++;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }

};