class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto x:map){
            int ele=x.first;
            int freq=x.second;
            pair<int,int>p={freq,-ele};
            pq.push(p);
        }
        vector<int>ans;
        while(pq.size()>0){
            int len=pq.top().first;
            for(int i=0;i<len;i++){
                ans.push_back(-pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};