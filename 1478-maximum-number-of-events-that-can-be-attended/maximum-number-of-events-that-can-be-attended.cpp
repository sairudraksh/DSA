class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        int count=0;
        int ans=events[0][0];
        while(!pq.empty() || i<n){
            while(i<n && ans==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                count++;
            }
            ans++;
            while(!pq.empty() && pq.top()<ans){
                pq.pop();
            }
        }
        return count;
    }
};