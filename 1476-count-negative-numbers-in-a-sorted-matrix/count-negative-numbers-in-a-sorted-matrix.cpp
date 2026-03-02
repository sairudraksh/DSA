class Solution {
public:
    int find(vector<int>&v){
        int n=v.size();

        for(int i=0;i<v.size();i++){
            if(v[i]<0) return n-i;
        }
        return 0;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            count+=find(grid[i]);
        }
        return count;
    }
};