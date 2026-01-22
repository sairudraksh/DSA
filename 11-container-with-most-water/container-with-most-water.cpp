class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int maximum=0;
        while(i<n){
            int j=n-1;

            while(j>i){
                int length=j-i;
                int breadth=min(nums[i],nums[j]);

                maximum=max(maximum,length*breadth);

                if(nums[i]<=nums[j]) break;
                j--;
            }
            i++;
        }
        return maximum;
    }
};