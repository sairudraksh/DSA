class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& v) {
        vector<vector<long long>>grid;

        int n=v.size();
        int m=v[0].size();
        grid.resize(n,vector<long long>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0) grid[i][j]+=grid[i-1][j];

                if(j-1>=0) grid[i][j]+=grid[i][j-1];

                if(i-1>=0 && j-1>=0) grid[i][j]-=grid[i-1][j-1];
            }
        }

        for(int i=0;i<m-1;i++){
            long long sum1=grid[n-1][i];

            long long sum2=grid[n-1][m-1]-sum1;

            if(sum1==sum2) return true;
        }

        for(int i=0;i<n-1;i++){
            long long sum1=grid[i][m-1];

            long long sum2=grid[n-1][m-1]-sum1;

            if(sum1==sum2) return true;

        }

        return false;

    }
};