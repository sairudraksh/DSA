class Solution {
public:
    int n;
    int dp[101][101][101];
    int find(vector<int>&boxes,int l,int r,int k){
        if(l>r) return 0;

        while(l<r && boxes[r]==boxes[r-1]){
            r--;
            k++;
        }
        if(dp[l][r][k]!=-1) return dp[l][r][k];// check here is this is the point where we woulld have stopped everytime because above we will reach every time after r--;
        int res=find(boxes,l,r-1,0)+((k+1)*(k+1));

        for(int i=l;i<r;i++){
            if(boxes[i]==boxes[r]){
                res=max(res,find(boxes,l,i,k+1)+find(boxes,i+1,r-1,0));
            }
        }
        return dp[l][r][k]=res;
    }
    int removeBoxes(vector<int>& boxes) {
        n=boxes.size();
        memset(dp,-1,sizeof(dp));
        return find(boxes,0,n-1,0);
    }
};