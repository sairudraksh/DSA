class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int i=0;
        int j=0;
        int n=nums.length();
        int maxlength=0;
        unordered_map<char,int>map;
        while(j<n){
            map[nums[j]]++;
            while(i<n && map[nums[j]]>1){
                map[nums[i]]--;
                if(map[nums[i]]==0) map.erase(nums[i]);
                i++;
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};