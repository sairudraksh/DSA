class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        int maximum=0;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            maximum=max(maximum,nums[i]);
        }
        vector<int>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                v.push_back(nums[i]);
            }
        }

        int count=0;
        int idx=0;
        for(int i=0;i<=maximum+n;i++){
            if(idx>=v.size()) break;
            if(map.find(i)==map.end()){
                if(v[idx]<=i){
                    count+=(i-v[idx]);
                    map[i]=1;
                    idx++;
                }
            }
        }
        return count;
    }
};