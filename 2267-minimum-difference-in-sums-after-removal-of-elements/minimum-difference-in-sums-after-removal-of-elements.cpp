class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;
        int k=n;
        vector<long long>prefix(N,0);
        vector<long long>suffix(N,0);


        priority_queue<int>leftheap;
        priority_queue<int,vector<int>, greater<int>> rightheap;


        long long leftsum=0;
        long long rightsum=0;
        for(int i=0;i<2*n;i++){
            leftsum+=nums[i];
            leftheap.push(nums[i]);
            if(leftheap.size()>k){
                leftsum-=leftheap.top();
                leftheap.pop();
            }
            prefix[i]=leftsum;
        }
        for(int i=N-1;i>=n;i--){
            rightsum+=nums[i];
            rightheap.push(nums[i]);
            if(rightheap.size()>k){
                rightsum-=rightheap.top();
                rightheap.pop();
            }
            suffix[i]=rightsum;
        }
        long long ans=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            long long diff=prefix[i]-suffix[i+1];
            ans=min(ans,diff);
        }
        return ans;
    }
};