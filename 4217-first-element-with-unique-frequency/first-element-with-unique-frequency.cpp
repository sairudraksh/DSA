class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        map<int,int>freq;
        for(auto x:mp){
            freq[x.second]++;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[mp[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};