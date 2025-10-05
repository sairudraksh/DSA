class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int ansCount=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1) count++;
            }
            if(count>ansCount){
                ansCount=count;
                row=i;
            }
        }
        // vector<int>v;
        // v.push_back(row)
        return {row,ansCount};

    }
};