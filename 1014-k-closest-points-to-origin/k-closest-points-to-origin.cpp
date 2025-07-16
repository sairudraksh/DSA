class Solution {
public:
    typedef pair<int,vector<int>>piv;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<piv>pq;
        for(auto v: points){
            int x=v[0];
            int y=v[1];
            int ans=x*x+y*y;
            pq.push({ans,v});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>v1;
        while(pq.size()>0){
            vector<int>v=pq.top().second;
            v1.push_back(v);
            pq.pop();
        }
        return v1;
    }
};