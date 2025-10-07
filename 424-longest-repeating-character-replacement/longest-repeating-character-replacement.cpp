class Solution {
public:
    int characterReplacement(string nums, int k) {
        int n=nums.length();
        int l=0;
        int r=0;

        unordered_map<char,int>map;
        int maxcount=0;
        int maxFreq=0;
        while(r<n){
            map[nums[r]]++;
            maxFreq=max(maxFreq,map[nums[r]]);
            while((r-l+1)-maxFreq>k){
                map[nums[l]]--;
                if(map[nums[l]]==0) map.erase(nums[l]);
                l++;
            }
            maxcount=max(maxcount,r-l+1);
            r++;
        }
        return maxcount;

    }
};