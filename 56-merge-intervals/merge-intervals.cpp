class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        int i=1;

        while(i<n){
            auto x=v.back();
            auto y=intervals[i];

            if(x[1]>=y[0]){
                v.pop_back();
                v.push_back({min(x[0],y[0]),max(x[1],y[1])});
            }
            else{
                v.push_back(intervals[i]);
            }
            i++;
        }
        return v;
    }
};