class Solution {
public:
    int characterReplacement(string nums, int k) {
        int n=nums.length();
        unordered_map<int,int>map;
        int r=0;
        int l=0;
        int ans=0;
        int maxlength=0;
        while(r<n){
            map[nums[r]]++;
            maxlength=max(maxlength,map[nums[r]]);
            if((r-l+1)-maxlength>k){
                map[nums[l]]--;
                if(map[nums[l]]==0) map.erase(nums[l]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};