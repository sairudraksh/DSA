class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int minabs=INT_MAX;
        long long sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=abs(nums[i][j]);
                sum+=x;
                if(nums[i][j]<0) count++;
                if(x<minabs) minabs=x;
            }
        }

        if(count%2==1){
            sum-=2*minabs;// 1 time as we already added it to make it 0 and second time we have to subtract it
        }
        return sum;
    }
};