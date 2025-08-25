class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>map;

        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.end()){
                pq.push(nums[i]);
            }
            map[nums[i]]++;
        }
        while(pq.size()>0){
            vector<int>v;
            for(int i=0;i<k;i++){
                if(pq.size()==0) return false;
                v.push_back(pq.top());
                map[pq.top()]--;
                pq.pop();
            }

            for(int i=0;i<v.size();i++){
                if(i!=0 && v[i]-v[i-1]!=1) return false;
                if(map[v[i]]==0){
                    map.erase(v[i]);
                }
                else{
                    pq.push(v[i]);
                }
            }
        }
        return true;
    }
};