class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;

        int n=arr.size();

        int prefix=0;
        int evencount=1;
        int oddcount=0;
        int ans=0;

        for(int i=0;i<n;i++){
            prefix+=arr[i];

            if(prefix%2==0){
                ans=(ans+oddcount)%mod;
                evencount++;
            }
            else{
                ans=(ans+evencount)%mod;
                oddcount++;
            }
        }
        return ans;
    }
};