class Solution {
public:
    int characterReplacement(string nums, int k) {
        int n=nums.size();
        int maxfreq=0;
        int ans=0;
        int l=0;
        int r=0;

        unordered_map<char,int>map;
        while(r<n){
            map[nums[r]]++;
            maxfreq=max(maxfreq,map[nums[r]]);

            if(r-l+1-maxfreq>k){
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