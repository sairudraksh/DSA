class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        if(v.size()==1) return 0;
        sort(v.begin(),v.end());
        int num=v[v.size()/2];
        int count=0;
        for(int i=0;i<v.size();i++){
            int l=abs(num-v[i]);

            if(l%x!=0) return -1;
            else count+=l/x;
        }
        return count;
    }
};