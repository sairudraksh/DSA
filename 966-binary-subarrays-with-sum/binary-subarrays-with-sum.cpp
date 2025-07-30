class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;

        map.insert({0,1});

        int currSum=0;
        int result=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];

            if(map.find(currSum-k)!=map.end()){
                result+=map[currSum-k];
            }

            map[currSum]++;
        }

        return result;
    }
};