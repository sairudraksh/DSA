class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<long long>lastavailable(n,0);
        vector<long long>roomsusedcount(n,0);
        for(int i=0;i<meetings.size();i++){
            long long start=meetings[i][0];
            long long end=meetings[i][1];
            long long d=end-start;
            long long minend=LLONG_MAX;
            int minidx=0;
            bool flag=true;
            for(int room=0;room<n;room++){
                if(lastavailable[room]<=start){
                    lastavailable[room]=end;
                    roomsusedcount[room]++;
                    flag=false;
                    break;
                }
                if(lastavailable[room]<minend){
                    minend=lastavailable[room];
                    minidx=room;
                }
            }
            if(flag){
                lastavailable[minidx]+=d;
                roomsusedcount[minidx]++;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(roomsusedcount[i]>roomsusedcount[ans]){
                ans=i;
            }
        }
        return ans;
    }
};
