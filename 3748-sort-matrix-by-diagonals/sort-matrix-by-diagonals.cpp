class Solution {
public:
    int n;
    void MakeMatrix(vector<vector<int>>& grid,int r,int c,bool nonIncreasing){
        vector<int>v;
        int i=r;
        int j=c;
        while(r<n && c<n){
            v.push_back(grid[r][c]);
            r++;
            c++;
        }

        if(nonIncreasing){
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
        }
        else{
            sort(v.begin(),v.end());
        }
        int k=0;
        while(i<n && j<n){
            grid[i][j]=v[k];
            i++;
            j++;
            k++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n=grid.size();

        for(int r=0;r<n;r++){
            MakeMatrix(grid,r,0,true);
        }

        for(int c=1;c<n;c++){
            MakeMatrix(grid,0,c,false);
        }

        return grid;
    }
};