class Solution {
public:
    int maxIceCream(vector<int>& nums, int total) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>total) break;
            else{
                total-=nums[i];
                count++;
            }
        }
        return count;
    }
};