class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int num=k%sum;
        for(int i=0;i<n;i++){
            if(nums[i]>num) return i;
            else num-=nums[i];
        }
        return 0;
    }
};