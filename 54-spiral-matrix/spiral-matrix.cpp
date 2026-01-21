class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int minr=0;
        int minc=0;
        int maxr=n-1;
        int maxc=m-1;
        vector<int>v;
        while(minr<=maxr && minc<=maxc){
            for(int i=minc;i<=maxc;i++){
                v.push_back(matrix[minr][i]);
            }
            minr++;
            if(minr>maxr || minc>maxc) break;

            for(int i=minr;i<=maxr;i++){
                v.push_back(matrix[i][maxc]);
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            for(int i=maxc;i>=minc;i--){
                v.push_back(matrix[maxr][i]);
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            for(int i=maxr;i>=minr;i--){
                v.push_back(matrix[i][minc]);
            }
            minc++;
        }
        return v;
    }
};