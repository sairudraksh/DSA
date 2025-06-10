class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto x: map){
            int ele=x.first;
            int freq=x.second;
            pair<int,int>p={freq,ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int>v;
        while(pq.size()>0){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;

    }
};