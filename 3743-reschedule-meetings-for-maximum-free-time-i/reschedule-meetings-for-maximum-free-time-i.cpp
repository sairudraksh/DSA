class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>v;
        v.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            v.push_back(startTime[i]-endTime[i-1]);
        }
        v.push_back(eventTime-endTime[endTime.size()-1]);
        int i=0;
        int j=0;
        int maxans=0;
        int ans=0;
        int n=v.size();
        while(j<n){
            ans+=v[j];
            while(i<n && j-i+1>k+1){
                ans-=v[i];
                i++;
            }
            maxans=max(ans,maxans);
            j++;
        }
        return maxans;
    }
};