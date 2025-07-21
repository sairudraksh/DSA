class Solution {
public:
    vector<vector<int>>ans;
    vector<int>dp;
    int find(int i){
        if(i>=ans.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int l=i+1;
        // for(int k=i+1;k<ans.size();k++){// this will give tle
        //     if(ans[k][0]>=ans[i][1]){
        //         x=k;
        //         break;
        //     }
        // }
        int r=ans.size()-1;
        int x=ans.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(ans[mid][0]>=ans[i][1]){
                r=mid-1;
                x=mid;
            }
            else{
                l=mid+1;
            }
        }
        return dp[i]=max(ans[i][2]+find(x),find(i+1));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        ans.clear();
        int n=startTime.size();
        for(int i=0;i<startTime.size();i++){
            ans.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(ans.begin(),ans.end());
        dp.resize(n+1,-1);
        return find(0);
    }
};