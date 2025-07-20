class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int N=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long>ongoing(n,0);
        vector<long long>countofroom(n,0);

        for(int i=0;i<meetings.size();i++){
            long long start=meetings[i][0];
            long long end=meetings[i][1];
            long long d=end-start;
            long long minans=LLONG_MAX;
            long long minidx=-1;
            bool flagg=true;
            for(int rooms=0;rooms<n;rooms++){
                if(ongoing[rooms]<=start){
                    ongoing[rooms]=end;
                    countofroom[rooms]++;
                    flagg=false;
                    break;
                }
                if(ongoing[rooms]<minans){
                    minans=ongoing[rooms];
                    minidx=rooms;
                }
            }
            if(flagg==true){
                ongoing[minidx]+=d;
                countofroom[minidx]++;
            }
        }
        int ans=0;
        int ansidx=0;
        for(int i=0;i<n;i++){
            if(countofroom[i]>ans){
                ans=countofroom[i];
                ansidx=i;
            }
        }
        return ansidx;
    }
};