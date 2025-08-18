class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maximum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i==0 && nums[i]!=1){
                nums[i]=1;
                
            }
            else if(i!=0){
                if(abs(nums[i]-nums[i-1])>1){
                    nums[i]=nums[i-1]+1;
                    
                }
            }
            maximum=max(maximum,nums[i]);
        }
        return maximum;
    }
};