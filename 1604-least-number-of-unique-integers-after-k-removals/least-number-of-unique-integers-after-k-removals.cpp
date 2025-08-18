class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto &x:map){
            pq.push(x.second);
        }
        while(pq.size()>0){
            if(pq.top()<=k){
                k=k-pq.top();
                pq.pop();
            }
            else break;
        }
        return pq.size();
    }
};