class Solution {
public:
    int n;
    bool isTrue(vector<int>&nums,vector<vector<int>>& queries,int t){
        vector<int>diff(nums.size(),0);
        for(int i=0;i<t;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            diff[l]+=queries[i][2];
            if(r+1<n){
                diff[r+1]-=queries[i][2];
            }
        }
        bool found=false;
        int extra=0;
        for(int j=0;j<nums.size();j++){
            extra+=diff[j];
            if(nums[j]-extra>0){
                found=true;
                break;
            }
        }
        if(found==false) return true;
        return false;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();

        bool found1=false;
        for(int i=0;i<nums.size();i++){//already zeroe array
            if(nums[i]!=0){
                found1=true;
                break;
            }
        }
        if(found1==false) return 0;

        int lo=0;
        int hi=queries.size();

        int ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isTrue(nums,queries,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
        
    }
};