class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(map.find(rem)!=map.end()){
                v.push_back(map[rem]);
                v.push_back(i);
            }
            else map[nums[i]]=i;
        }
        return v;
    }
};