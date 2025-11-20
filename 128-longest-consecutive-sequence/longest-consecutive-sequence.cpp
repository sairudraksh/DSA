class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int curr=0;
        int maxcount=0;
        int prev=INT_MAX;

        for(int i=0;i<n;i++){
            if(prev==INT_MAX || nums[i]==prev+1){
                curr++;
                prev=nums[i];
            }
            else if(prev==nums[i]) continue;
            else{
                curr=1;
                prev=nums[i];
            }
            maxcount=max(maxcount,curr);
        }
        return maxcount;
    }
};