class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>set;

        int j=0;
        int i=0;
        int sum=0;
        int maxsum=0;
        while(j<n){
            if(set.find(nums[j])==set.end()){
                sum+=nums[j];
                set.insert(nums[j]);
                maxsum=max(sum,maxsum);
                j++;
            }
            else{
                sum-=nums[i];
                set.erase(nums[i]);
                i++;
            }
        }
        return maxsum;
    }
};