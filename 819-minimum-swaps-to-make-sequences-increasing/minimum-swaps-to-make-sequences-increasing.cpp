class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>& nums1, vector<int>& nums2,int i,bool rev){
        if(i>=nums1.size()) return 0;

        if(dp[i][rev]!=-1) return dp[i][rev];

        int a=INT_MAX;
        int b=INT_MAX;

        if(i==0){
            a=find(nums1,nums2,i+1,false);

            b=find(nums1,nums2,i+1,true);
            if(b!=INT_MAX) b+=1;

            return dp[i][rev]=min(a,b);
        }
        else{
            if(rev==false){
                if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]){
                    a=find(nums1,nums2,i+1,true);
                    if(a!=INT_MAX) a+=1;
                }
                if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i]){
                    b=find(nums1,nums2,i+1,false);
                    
                }
            }
            else{
                if(nums2[i-1]<nums2[i] && nums1[i-1]<nums1[i]){
                    a=find(nums1,nums2,i+1,true);
                    if(a!=INT_MAX) a+=1;
                }
                if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]){
                    b=find(nums1,nums2,i+1,false);
                }
            }
        }
        return dp[i][rev]=min(a,b);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size()+1,vector<int>(2,-1));
        return find(nums1,nums2,0,false);
    }
};