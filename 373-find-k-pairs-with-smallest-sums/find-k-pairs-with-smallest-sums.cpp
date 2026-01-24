class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>>v;
        set<pair<int,int>>visited;
        while(k--){
            if(pq.size()==0){
                v.push_back({nums1[0],nums2[0]});
                visited.insert({0,0});
                if(1<n){
                    int sum=nums1[1]+nums2[0];
                    pq.push({sum,{1,0}});
                    visited.insert({1,0});
                }
                if(1<m){
                    int sum=nums1[0]+nums2[1];
                    pq.push({sum,{0,1}});
                    visited.insert({0,1});
                }
            }
            else{
                auto x=pq.top();
                pq.pop();
                auto y=x.second;
                int i=y.first;
                int j=y.second;
                v.push_back({nums1[i],nums2[j]});

                if(i+1<n && !visited.count({i+1,j})){
                    int sum=nums1[i+1]+nums2[j];
                    pq.push({sum,{i+1,j}});
                    visited.insert({i+1,j});
                }
                if(j+1<m && !visited.count({i,j+1})){
                    int sum=nums1[i]+nums2[j+1];
                    pq.push({sum,{i,j+1}});
                    visited.insert({i,j+1});
                }
            }
        }
        return v;
    }
};