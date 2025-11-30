class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        double prefix=1;
        double suffix=1;;
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            maximum=max(maximum,max((int)prefix,(int)suffix));
        }
        return maximum;
    }
};