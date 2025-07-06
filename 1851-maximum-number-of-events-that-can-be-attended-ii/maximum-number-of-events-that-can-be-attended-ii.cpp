class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0]<b[0]; 
    }
    vector<vector<int>>dp;
    int find(vector<vector<int>>& events,int i,int k){
        if(i>=events.size() || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int x=events.size();
        for(int l=i+1;l<events.size();l++){
            if(events[l][0]>events[i][1]){
                x=l;
                break;
            }
        }
        int a=0;
        if(k>0) a=events[i][2]+find(events,x,k-1);
        return dp[i][k]=max(a,find(events,i+1,k));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end(),cmp);
        dp.resize(n+1,vector<int>(k+1,-1));
        return find(events,0,k);
    }
};