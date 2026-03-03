class Solution {
public:
    bool isTrue(vector<int>& nums,int mid,int m){
        int count=1;
        int i=0;
        int j=1;
        int n=nums.size();
        while(j<n){
            if(nums[j]-nums[i]>=mid){
                count++;
                i=j;
                j++;
            }
            else j++;
        }
        return count>=m;
    }
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums[nums.size()-1];
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isTrue(nums,mid,m)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};