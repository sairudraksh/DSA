class Solution {
public:
    void rotate(int i,int j,vector<int>&nums){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>v;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        k=k%(n*m);
        int l=v.size();
        rotate(0,l-k-1,v);
        rotate(l-k,l-1,v);
        rotate(0,l-1,v);

        vector<vector<int>>ans;
        int p=0;
        for(int i=0;i<n;i++){
            vector<int>v1;
            for(int j=0;j<m;j++){
                v1.push_back(v[p]);
                p++;
            }
            ans.push_back(v1);
        }

        return ans;
    }
};