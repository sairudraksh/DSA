class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long count=0;
        for(int i=0;i<n-1;i++){
            for(int j=n-1;j>i;j--){
                for(int k=j-1;k>i;k--){
                    long long a=nums[i];
                    long long b=nums[j];
                    long long c=nums[k];

                    if(a+b>c && b+c>a && a+c>b) count++;
                }
            }
        }
        return count;
    }
};