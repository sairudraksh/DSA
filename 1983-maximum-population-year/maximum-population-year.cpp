class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>>v;
        int n=logs.size();
        for(int i=0;i<n;i++){
            v.push_back({logs[i][0],+1});
            v.push_back({logs[i][1],-1});
        }
        
        sort(v.begin(),v.end());
        int currpop=0;
        int maxpop=0;
        int ans=1950;
        for(int i=0;i<v.size();i++){
            currpop+=v[i][1];
            if(currpop>maxpop){
                maxpop=currpop;
                ans=v[i][0];
            }
        }
        return ans;
    }
};