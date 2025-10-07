class Solution {
public:
    int find(vector<int>&nums,int k){
        int n=nums.size();
        int l=0;
        int r=0;

        long long count=0;
        int oddcount=0;

        while(r<n){
            if(nums[r]%2!=0) oddcount++;
            while(oddcount>k){
                if(nums[l]%2!=0) oddcount--;
                l++;
            }
            count+=(n-l+1);
            r=r+1;
        }
        return (int)count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=find(nums,k);
        int b=find(nums,k-1);
        return a-b;
    }
};