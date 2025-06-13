class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        if (arr[0][0]==1) return 0; //Obstacle at start
        arr[0][0]=1;
        for (int j=1;j<m;j++){
            if (arr[0][j]==1) arr[0][j]=0;
            else arr[0][j]=arr[0][j-1];
        }
        for (int i=1; i<n;i++) {
            if (arr[i][0]==1) arr[i][0] = 0;
            else arr[i][0]=arr[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if (arr[i][j] == 1) {
                    arr[i][j] = 0;
                    continue;
                }
                int a=arr[i-1][j];
                int b=arr[i][j-1];
                arr[i][j]=a+b;
            }
        }
        return arr[n-1][m-1];

    }
};