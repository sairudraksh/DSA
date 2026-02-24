class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            auto v1=v[v.size()-1];
            auto v2=intervals[i];

            if(v1[1]>=v2[0]){
                v.pop_back();
                int a=min(v1[0],v2[0]);
                int b=max(v1[1],v2[1]);
                v.push_back({a,b});
            }
            else{
                v.push_back(v2);
            }
        }
        return v;
    }
};