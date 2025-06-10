class Solution {
public:
    typedef pair<int,vector<int>>piv;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<piv>pq;
        for(auto v:arr){
            int x=v[0];
            int y=v[1];
            int dis=x*x+y*y;
            pq.push({dis,v});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            vector<int>v=pq.top().second;
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};