class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maximum=0;
        while(j<n){
            if(nums[j]==0 && k>0){
                k--;
            }
            else if(nums[j]==0 && k==0){
                if(nums[i]==0){
                    i++;
                    k++;
                }
                else{
                    while(nums[i]==1){
                        i++;
                    }
                    i++;
                    k++;
                }
                k--;
            }
            maximum=max(maximum,j-i+1);
            j++;
        }
        return maximum;
    }
};