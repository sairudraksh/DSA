class Solution {
public:
    int find(vector<int>&nums,int i,int j){
        int minimum=INT_MAX;
        int maximum=INT_MIN;
        for(int k=i;k<=j;k++){
            if(nums[k]<minimum) minimum=nums[k];
            if(nums[k]>maximum) maximum=nums[k];
        }
        return maximum-minimum;
    }
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
            int l=i;
            int r=(i+k)-1;
            if(r>=n) break;
            int diff=find(nums,l,r);
            minimum=min(minimum,diff);
        }
        return minimum;
    }
};