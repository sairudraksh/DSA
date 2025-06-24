class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int count=0;
        while(i<=j){
            if(nums[i]+nums[j]<=limit){
                count++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>limit){
                count++;
                j--;
            }
            else if(i==j){
                count++;
                break;
            }
        }
        return count;
    }
};