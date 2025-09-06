class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& grid) {
        int n=grid.size();
        int maximumDiagonal=0;
        int maxarea=0;
        for(int i=0;i<n;i++){
            int x=grid[i][0];
            int y=grid[i][1];

            int diagonal=x*x+y*y;

            if((diagonal>maximumDiagonal) || (diagonal==maximumDiagonal && x*y>maxarea)){
                maxarea=x*y;
                maximumDiagonal=x*x+y*y;
            }
        }
        return maxarea;
    }
};