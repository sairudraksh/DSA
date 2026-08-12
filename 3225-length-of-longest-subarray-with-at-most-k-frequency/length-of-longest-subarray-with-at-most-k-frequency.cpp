class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int i=0;
        int j=0;
        int n=nums.size();
        int maxlen=INT_MIN;
        while(i<n && j<n){
            map[nums[j]]++;
            while(map[nums[j]]>k){
                map[nums[i]]--;
                if(map[nums[i]]==0) map.erase(nums[i]);
                i++;
            }
            maxlen=max(maxlen,(j-i)+1);
            j++;
        }
        return maxlen;
    }
};