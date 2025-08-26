class Solution {
public:
    int find(vector<int>&nums,int &k,int mid){
        int continous=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                continous++;

            }
            if(continous==k){
                count++;
                continous=0;
            }
            if(nums[i]>mid){
                continous=0;
            }
        }
        return count;
    }
    int minDays(vector<int>&nums, int m, int k) {
        int start=0;
        int end=-1;
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
        }
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            int a=find(nums,k,mid);

            if(a>=m){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};