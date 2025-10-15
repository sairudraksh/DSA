class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=1;
        int maximum=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                prev=curr;
                curr=1;
            }
            else{
                curr++;
            }
            maximum=max(maximum,curr/2);
            maximum=max(maximum,min(prev,curr));
        }
        return maximum;
    }
};