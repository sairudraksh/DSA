class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int count=0;
        int i=0;
        int day=events[0][0];
        while(i<n || !pq.empty()){
            while(i<n && day==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                count++;
                pq.pop();
            }
            day++;
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return count;
    }
};