class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=0;
        suffix[n-1]=0;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i+1];
        }
        int sum=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            sum=abs(prefix[i]-suffix[i]);
            v.push_back(sum);
        }
        return v;
        
    }
};