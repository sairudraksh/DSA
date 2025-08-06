class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i=0;
        int j=n-1;

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

            if(i==j){
                count++;
                break;
            }
        }

        return count;

    }
};