class Solution {
public:
    vector<vector<long long>>jobs;
    vector<long long>dp;
    int find(long long i){
        if(i>=jobs.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long x=jobs.size();
        long long l=i+1;
        long long r=jobs.size()-1;
        while(l<=r){
            long long mid=(r+l)/2;
            if(jobs[mid][0]>=jobs[i][1]){
                x=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        long long a=jobs[i][2]+find(x);
        long long b=find(i+1);
        return dp[i]=max(a,b);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        jobs.clear();
        for(long long i=0;i<startTime.size();i++){
            jobs.push_back({(long long)startTime[i],(long long)endTime[i],(long long)profit[i]});
        }
        dp.resize(startTime.size()+1,-1);
        sort(jobs.begin(),jobs.end());
        return find(0);
    }
};