class Solution {
public:
    int minSetSize(vector<int>& nums) {
        int n=nums.size();
        int l=n;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        priority_queue<int>pq;
        for(auto &x:map){
            pq.push(x.second);
        }
        int count=0;
        while(pq.size()>0){
            n-=pq.top();
            pq.pop();
            count++;
            if(n<=(l/2)) break;
        }
        return count;
    }
};