class Solution {
public:
     static bool cmp(const vector<int>& a,const vector<int>& b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int prevalue=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(prevalue>intervals[i][0]){
                count++;
            }
            else{
                prevalue=intervals[i][1];
            }
        }
        return count;
    }
};