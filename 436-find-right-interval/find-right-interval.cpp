class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>v;
        unordered_map<int,int>map;
        for(int i=0;i<intervals.size();i++){
            v.push_back(intervals[i][0]);
            map[intervals[i][0]]=i;
        }
        sort(v.begin(),v.end());
        vector<int>vec;
        for(int i=0;i<n;i++){
            int curr=intervals[i][1];
            int currIdx=map[intervals[i][0]];

            int lo=0;
            int hi=v.size()-1;
            int ans=-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;

                if(v[mid]>=curr){
                    hi=mid-1;
                    ans=map[v[mid]];
                }
                else lo=mid+1;
            }
            vec.push_back(ans);
        }
        return vec;
    }
};