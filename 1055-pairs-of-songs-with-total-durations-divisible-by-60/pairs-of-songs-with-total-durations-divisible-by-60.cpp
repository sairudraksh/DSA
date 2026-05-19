class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
        unordered_map<int,int>map;
        int count=0;

        for(int i=0;i<nums.size();i++){
            int x=nums[i]%60;

            int need=(60-x)%60;

            count+=map[need];

            map[x]++;
        }
        return count;
    }
};