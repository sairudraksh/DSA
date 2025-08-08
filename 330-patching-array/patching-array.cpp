class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        long long maxans=0;
        int count=0;

        while(maxans<n){
            if(i<nums.size() && maxans+1>=nums[i]){
                maxans+=nums[i];
                i++;
            }
            else{
                maxans+=maxans+1;
                count++;
            }
        }

        return count;
    }
};