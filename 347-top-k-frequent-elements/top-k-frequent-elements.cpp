class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x1: mp){
            pq.push(x1.second);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(pq.size()==0) break;
            for(auto x: mp){
                if(x.second==pq.top()){
                    ans.push_back(x.first);
                    pq.pop();
                    if(pq.size()==0) break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};