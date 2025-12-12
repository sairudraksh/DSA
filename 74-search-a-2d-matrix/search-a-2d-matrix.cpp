class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(matrix[mid][m-1]>=target){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        if(ans==-1) return false;
        int row=ans;
        int i=0;
        int j=m-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
};