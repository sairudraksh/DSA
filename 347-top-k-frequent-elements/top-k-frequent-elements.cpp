class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto &x:map){
            pq.push({x.second,x.first});
        }

        vector<int>ans;
        while(pq.size()>0 && k--){
            auto x=pq.top();
            ans.push_back(x.second);
            pq.pop();
        }

        return ans;
    }
};