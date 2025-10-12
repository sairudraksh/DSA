class Solution {
public:
    vector<int>findpge(vector<int>&nums){
        int n=nums.size();
        vector<int>v(n,nums[0]);

        for(int i=1;i<n;i++){
            v[i]=max(v[i-1],nums[i-1]);
        }
        return v;
    }
    vector<int>findnge(vector<int>&nums){
        int n=nums.size();
        vector<int>v(n,nums[n-1]);

        for(int i=n-2;i>=0;i--){
            v[i]=min(v[i+1],nums[i+1]);
        }
        return v;
    }
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge=findnge(nums);
        vector<int>pge=findpge(nums);   
        int count=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nge[i]>nums[i] && pge[i]<nums[i]) count+=2;
            else if(nums[i-1]<nums[i] && nums[i+1]>nums[i]) count++;
        }
        return count;
    }
};