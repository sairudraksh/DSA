class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp1(n ,1);
	vector<int>dp2(n,1);
	for(int i=0;i<n;i++){
		for(int prev=0;prev<i;prev++){
			if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i]){
				dp1[i]=1+dp1[prev];
			}
		}

	}

	for(int i=n-1;i>=0;i--){
		for(int prev=n-1;prev>i;prev--){
			if(arr[prev]<arr[i] && 1+dp2[prev]>dp2[i]){
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

        return n-maxMountain;

        
    }
};