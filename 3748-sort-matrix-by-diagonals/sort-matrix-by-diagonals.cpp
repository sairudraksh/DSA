class Solution {
public:
    void sortdiadonally(int i,int j,vector<vector<int>>& grid,bool asc){
        int n=grid.size();
        int r=i;
        int c=j;

        vector<int>v;
        while(i<n && j<n){
            v.push_back(grid[i][j]);
            i++;
            j++;
        }
        i=r;
        j=c;
        if(asc){
            sort(v.begin(),v.end());
            for(int k=0;k<v.size();k++){
                grid[i][j]=v[k];
                i++;
                j++;
            }
        }

        if(!asc){
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            for(int k=0;k<v.size();k++){
                grid[i][j]=v[k];
                i++;
                j++;
            }
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        for(int i=0;i<n;i++){
            sortdiadonally(i,0,grid,false);
        }

        for(int i=1;i<n;i++){
            sortdiadonally(0,i,grid,true);
        }

        return grid;
    }
};