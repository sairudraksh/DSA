class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto &x:map){
            pq.push({x.second,-x.first});
        }
        vector<int>v;
        while(pq.size()>0){
            auto x=pq.top();
            for(int i=0;i<x.first;i++){
                v.push_back(-x.second);
            }
            pq.pop();
        }
        return v;
    }
};