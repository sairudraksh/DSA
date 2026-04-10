class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int minimum=INT_MAX;
        for(int i=0;i<n-2;i++){
            int num=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]==num){
                    for(int k=j+1;k<n;k++){
                        if(nums[k]==nums[j]){
                            int a=abs(i-j);
                            int b=abs(j-k);
                            int c=abs(k-i);
                            minimum=min(minimum,a+b+c);
                        }
                    }
                }
            }
        }
        if(minimum==INT_MAX) return -1;
        return minimum;
    }
};