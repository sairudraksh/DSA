class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>>matrix;
        matrix.resize(n,vector<int>(m,0));

        for(int j=0;j<indices.size();j++){
            int r=indices[j][0];
            int c=indices[j][1];
            
            for(int i=0;i<m;i++){
                matrix[r][i]++;
            }
            for(int i=0;i<n;i++){
                matrix[i][c]++;
            }
                
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]%2!=0) count++;
            }
        }

        return count;
    }
};