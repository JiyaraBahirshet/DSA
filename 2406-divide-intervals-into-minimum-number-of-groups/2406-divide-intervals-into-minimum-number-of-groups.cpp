class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>start(n);
        vector<int>end(n);
        for(int i=0;i<n;i++){
            start[i]=intervals[i][0];
            end[i]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;
        int j=0;
        int cnt=0;
        int maxcnt=0;
        while(i<n){
            if(start[i]<=end[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};