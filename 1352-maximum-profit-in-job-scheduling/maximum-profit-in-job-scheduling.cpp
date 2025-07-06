class Solution {
public:
    vector<long long>dp;
    vector<vector<long long>>jobs;
    long long find(long long i){
        if(i>=jobs.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long l =i+1, r =jobs.size()-1, x = jobs.size();
        while(l<=r) {
            long long mid=(r+l)/2;
            if (jobs[mid][0]>=jobs[i][1]) {
                x=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return dp[i]=max(jobs[i][2]+find(x),find(i+1));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        long long n=endTime.size();
        jobs.clear();
        for(long long i=0;i<n;i++){
            jobs.push_back({(long long) startTime[i],(long long) endTime[i],(long long) profit[i]});
        }
        dp.resize(n+1,-1);
        sort(jobs.begin(),jobs.end());
        return (int)find(0);
    }
};