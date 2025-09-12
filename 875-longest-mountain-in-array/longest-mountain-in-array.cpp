class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp1(n ,1);
        vector<int>dp2(n,1);
        for(int i=0;i<n;i++){
            if(i!=0){
                int prev=i-1;
                if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i] && prev==i-1){
                    dp1[i]=1+dp1[prev];
                }
            }

        }

        for(int i=n-1;i>=0;i--){
            if(i!=n-1){
                int prev=i+1;
                if(arr[prev]<arr[i] && 1+dp2[prev]>dp2[i] && prev==i+1){
                    dp2[i]=1+dp2[prev];
                }
            }
        }

         int maxMountain=0;
        for (int i=1;i<n-1;i++) { 
            if (dp1[i]>1 && dp2[i]>1) {
                maxMountain=max(maxMountain,dp1[i]+dp2[i]-1);
            }
        }

        return maxMountain;

        
    }
};