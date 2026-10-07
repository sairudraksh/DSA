class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>v;
        for(int i=0;i<n;i++){
            long long num=nums[i]*nums[i];
            v.push_back(num);
        }
        long long sum=0;
        long long diff=0;
        sort(v.begin(),v.end());

        for(int i=n-1;i>=n/2;i--){
            sum+=v[i];
        }

        for(int i=n/2-1;i>=0;i--){
            diff+=v[i];
        }
        return sum-diff;
    }
};