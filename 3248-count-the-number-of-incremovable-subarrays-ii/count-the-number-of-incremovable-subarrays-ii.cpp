class Solution {
public:
    long long find(vector<int>&v1,vector<int>&v2){
        int n=v1.size();
        int m=v2.size();

        int i=0;
        int j=0;
        long long ans=0;


        while(i<n && j<m){
            if(v1[i]<v2[j]){
                ans+=(m-j);
                i++;
            }
            else j++;
        }
        return ans;

    }
    long long incremovableSubarrayCount(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        if(n==1) return 1;
        vector<int>arr1;
        vector<int>arr2;

        while(i+1<n && nums[i]<nums[i+1]){
            arr1.push_back(nums[i]);
            i++;
        }
        arr1.push_back(nums[i]);

        int j=n-1;

        while(j-1>=0 && nums[j]>nums[j-1]){
            arr2.push_back(nums[j]);
            j--;
        }
        arr2.push_back(nums[j]);
        reverse(arr2.begin(),arr2.end());

        long long ans=0;
        if(i>j){
            ans+=(1LL*n*(n+1)*1LL)/2;
            return ans;
        }
        ans+=arr1.size();
        ans+=arr2.size();
        ans++;
        return ans+=find(arr1,arr2);
    }
};