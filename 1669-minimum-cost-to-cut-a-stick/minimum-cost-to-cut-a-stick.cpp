class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&cuts,int left,int right){
        if(left+1==right || left>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int minimum=INT_MAX;
        for(int i=left+1;i<=right-1;i++){
            minimum=min(minimum,(cuts[right]-cuts[left])+find(cuts,left,i)+find(cuts,i,right));
        }
        if(minimum==INT_MIN) return dp[left][right]=0;
        return dp[left][right]=minimum;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);

        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        dp.resize(m+1,vector<int>(m+1,-1));
        return find(cuts,0,cuts.size()-1);
    }
};