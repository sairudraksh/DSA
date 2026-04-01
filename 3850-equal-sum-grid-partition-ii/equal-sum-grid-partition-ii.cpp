class Solution {
public:
    bool exists(vector<vector<int>>& grid,unordered_map<long long,int>&map,int i,int n,int j,int m,long long diff){
        int rows=n-i+1;
        int cols=m-j+1;

        if(rows*cols==1) return false;

        if(rows==1){
            return (grid[i][j]==diff || grid[i][m]==diff);
        }

        if(cols==1){
            return (grid[i][j]==diff || grid[n][j]==diff);
        }
        if(map[diff]>0) return true;
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        unordered_map<long long,int>top;
        unordered_map<long long,int>left;
        unordered_map<long long,int>bottom;
        unordered_map<long long,int>right;

        long long sum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];

                bottom[grid[i][j]]++;
                right[grid[i][j]]++;

            }
        }

        long long sumTop=0;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                top[grid[i][j]]++;
                sumTop+=grid[i][j];
                bottom[grid[i][j]]--;
            }
            long long sumBottom=sum-sumTop;

            if(sumTop==sumBottom){
                return true;
            }

            long long diff=abs(sumTop-sumBottom);

            if(sumTop>sumBottom){
                if(exists(grid,top,0,i,0,m-1,diff)) return true;
            }
            else{
                if(exists(grid,bottom,i+1,n-1,0,m-1,diff)) return true;
            }
        }

        long long sumLeft=0;

        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                sumLeft+=grid[j][i];
                right[grid[j][i]]--;
                left[grid[j][i]]++;
            }

            long long sumRight=sum-sumLeft;

            long long diff=abs(sumLeft-sumRight);

            if(sumLeft==sumRight) return true;

            if(sumLeft>sumRight){
                if(exists(grid,left,0,n-1,0,i,diff)) return true;
            }
            else{
                if(exists(grid,right,0,n-1,i+1,m-1,diff)) return true;
            }
        }

        return false;

    }
};