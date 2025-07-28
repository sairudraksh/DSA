class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];

            int diff=x*x +y*y;
            pq.push({diff,x,y});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            vector<int>v=pq.top();
            ans.push_back({v[1],v[2]});
            pq.pop();
        }
        return ans;
    }
};