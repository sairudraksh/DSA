class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int n=nums.size();
        vector<int>prefix(n,nums[0]);

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int i=0;
        int count=0;
        map[0]=1;
        while(i<n){
            int curr=prefix[i];
            int need=curr-k;
            int freq=map[need];
            count+=(freq);
            map[curr]++;
            i++;
        }

        return count;
    }
};