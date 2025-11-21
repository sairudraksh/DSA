class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();// Firstly we will find all the pairs of where qnique elements are less than equal to k and than less than equal to k-1 and then subtract both and we will get unique elements equal to k
        unordered_map<int,int>map;
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            map[nums[j]]++;
            while(i<n && map.size()>k){
                map[nums[i]]--;
                if(map[nums[i]]==0) map.erase(nums[i]);
                i++;
            }
            count=count+(j-i+1);
            j++;
        }
        i=0;
        j=0;
        unordered_map<int,int>mp;
        int count2=0;
        while(j<n){
            mp[nums[j]]++;
            while(i<n && mp.size()>k-1){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            count2=count2+(j-i+1);
            j++;
        }
        return count-count2;
    }
};