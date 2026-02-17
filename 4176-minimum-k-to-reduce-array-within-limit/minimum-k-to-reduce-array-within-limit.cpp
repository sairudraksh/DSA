class Solution {
public:
    int find(vector<int>&nums,int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            count+=num/k;
            if(num%k!=0) count++;
        }
        return count;
    }
    int minimumK(vector<int>& nums){
        int n=nums.size();
        int hi=n;
        for(int i=0;i<n;i++){
            hi=max(hi,nums[i]);
        }
        int lo=1;
        int ans=nums.size();
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            long long a=find(nums,mid);
            long long t=mid*mid;
            if(a<=t){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};