class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int i=0;
        int minsum=INT_MAX;
        int sum=0;
        int x=arr.size()-k;
        for(int l=0;l<x;l++){
            sum+=arr[l];
        }
        int j=x-1;
        minsum=min(minsum,sum);
        int total=0;
        int n=arr.size();
        for(int p=0;p<n;p++){
            total+=arr[p];
        }
        while(j<n-1){
            j++;
            sum+=arr[j];
            sum-=arr[i];
            i++;
            minsum=min(minsum,sum);
        }
        return total-minsum;
    }
};