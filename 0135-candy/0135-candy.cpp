class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1;
        int i=1;
        while(i<ratings.size()){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<ratings.size() && ratings[i]>ratings[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<ratings.size() && ratings[i]<ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
};