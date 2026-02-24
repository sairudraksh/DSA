class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v1;
        vector<int>v2;
        int oldsum=0;
        for(int i=0;i<n;i++){
            int maximum1=0;
            int maximum2=0;
            for(int j=0;j<n;j++){
                maximum1=max(maximum1,grid[i][j]);
                maximum2=max(maximum2,grid[j][i]);
                oldsum+=grid[i][j];
            }
            v1.push_back(maximum1);
            v2.push_back(maximum2);
        }
        int sum=0;
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==v1[i] || grid[i][j]==v2[j]){
                    sum+=grid[i][j];
                }
                else{
                    sum+=min(v1[i],v2[j]);
                }
            }
        }
        return sum-oldsum;
    }
};