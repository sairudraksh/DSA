class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);

        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]) left[i]+=left[i-1];
            if(arr[n-1-i]>arr[n-i]) right[n-1-i]+=right[n-i];
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};