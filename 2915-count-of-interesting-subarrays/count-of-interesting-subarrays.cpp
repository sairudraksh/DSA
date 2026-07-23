class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                v.push_back(1);
            }
            else v.push_back(0);
        }
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        unordered_map<int,int>map;
        map[0]=1;
        long long count=0;
        for(int i=0;i<n;i++){
            int curr=v[i]%modulo;

            int need=(curr-k+modulo)%modulo;
            count+=map[need];
            map[curr]++;
        }
        return count;
    }
};