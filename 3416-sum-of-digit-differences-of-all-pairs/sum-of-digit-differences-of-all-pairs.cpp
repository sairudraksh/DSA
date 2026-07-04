class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans=0;
        vector<vector<int>>freq(10,vector<int>(10,0));
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];

            for(int i=0;num>0;num=num/10,i++){
                freq[i][num%10]++;
            }
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                ans+=freq[i][j]*(nums.size()-freq[i][j]);
            }
        }
        return ans/2;
    }
};