class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        int n=nums.size();
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++){
            if(i%2==0) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            int target=i;
            int minsum=INT_MAX;

            int sum=0;

            for(int j=0;j<v1.size();j++){
                int num=v1[j];
                int left=num%k;
                int t=num;
                num=num-left;
                sum+=min(abs(target-left),k-abs(target-left));
            }

            for(int l=0;l<k;l++){
                if(l==target) continue;
                int target1=l;

                int sum1=0;

                for(int p=0;p<v2.size();p++){
                    int num=v2[p];
                    int left=num%k;
                    num=num-left;
                    sum1+=min(abs(target1-left),k-abs(target1-left));
                }
                minsum=min(minsum,sum1+sum);
            }

            ans=min(ans,minsum);
        }
        return ans;
    }
};