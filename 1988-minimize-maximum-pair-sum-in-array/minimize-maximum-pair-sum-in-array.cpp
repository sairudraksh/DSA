class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int maximum=0;
        while(i<j){
            int sum=nums[i]+nums[j];
            maximum=max(maximum,sum);
            i++;
            j--;
        }
        return maximum;
    }
};