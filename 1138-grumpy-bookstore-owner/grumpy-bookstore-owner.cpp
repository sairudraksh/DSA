class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k=minutes;
        vector<int>&arr=customers;
        int n=arr.size();
        int prevloss=0;
        for(int i=0;i<k;i++){
            if(grumpy[i]==1) prevloss+=arr[i];
        }
        int maxloss=prevloss;
        int maxIdx=0;
        int i=1;
        int j=k;
        while(j<n){
            int currloss=prevloss;
            if(grumpy[j]==1) currloss+=arr[j];
            if(grumpy[i-1]==1) currloss-=arr[i-1];
            if(maxloss<currloss){
                maxloss=currloss;
                maxIdx=i;
            }
            prevloss=currloss;
            i++;
            j++;
        }
        for(int i=maxIdx;i<maxIdx+k;i++){
            grumpy[i]=0;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=arr[i];
        }
        return sum;

    }
};