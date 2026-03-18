class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 0;
        int i=0;
        int j=2;
        int count=0;
        int curr=nums[1]-nums[0];
        int ans=0;
        while(j<n){
            if(nums[j]-nums[j-1]==curr){
                if(j-i+1>=3){
                    ans=ans+(j-i-1);// number of subarrays that could havce been formed
                }
            }
            else{
                curr=nums[j]-nums[j-1];
                i=j-1;
            }
            j++;
        }
        return ans;
    }
};