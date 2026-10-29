class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();

        vector<vector<int>>nums;

        for(int i=0;i<n;i++){
            nums.push_back({trips[i][1],trips[i][2],trips[i][0]});
        }
        sort(nums.begin(),nums.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int curr=0;
        for(int i=0;i<n;i++){
            while(pq.size()>0 && pq.top().first<=nums[i][0]){
                curr-=pq.top().second;
                pq.pop();
            }
            curr+=nums[i][2];
            pq.push({nums[i][1],nums[i][2]});
            if(curr>capacity) return false;
        }
        return true;
    }
};