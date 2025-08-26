class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>& cuts,int left,int right){
        if(right-left<=1) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int maximum=INT_MAX;
        for(int i=left+1;i<=right-1;i++){
            int ans=(cuts[right]-cuts[left])+find(cuts,left,i)+find(cuts,i,right);

            maximum=min(maximum,ans);
        }
        return dp[left][right]=maximum;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);
        dp.resize(103,vector<int>(103,-1));

        return find(cuts,0,cuts.size()-1);
    }
};