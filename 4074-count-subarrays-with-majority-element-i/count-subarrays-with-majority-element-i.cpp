class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>map;
            for(int j=i;j<n;j++){
                map[nums[j]]++;
                if(map[target]>(j-i+1)/2) count++;
            }
        }
        return count;
    }
};