class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int longest=0;
        int count=0;
        int lastSmaller=INT_MIN;

        for(int i=0;i<n;i++){
            if(lastSmaller==INT_MIN || (nums[i]-1)==lastSmaller){
                count++;
                lastSmaller=nums[i];
            }
            else if(nums[i]==lastSmaller) continue;

            else{
                count=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,count);
        }
        return longest;
    }
};