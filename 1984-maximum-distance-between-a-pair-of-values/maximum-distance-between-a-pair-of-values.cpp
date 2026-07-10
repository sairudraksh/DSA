class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=n-1;
        int j=m-1;
        int ans=0;
        while(i>=0 && j>=0){
            if(nums1[i]<=nums2[j]){
                ans=max(ans,(j-i));
                i--;
            }
            else{
                if(j-1<i){
                    i--;
                    j--;
                }   
                else j--;
            }
        }
        return ans;
    }
};