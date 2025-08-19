class Solution {
public:
    int  minimumCost(int m, int n, vector<int>& horizontal, vector<int>& vertical) {
        sort(horizontal.begin(), horizontal.end(), greater<int>());
        sort(vertical.begin(), vertical.end(), greater<int>());
        int x=horizontal.size();
        int y=vertical.size();

        int i=0;
        int j=0;

        int horizontalpieces=1;
        int verticalpieces=1;

        int result=0;

        while(i<x && j<y){
            if(horizontal[i]>=vertical[j]){
                result+=horizontal[i]*verticalpieces;
                horizontalpieces++;
                i++;
            }
            else{
                result+=vertical[j]*horizontalpieces;
                verticalpieces++;
                j++;
            }
        }
        while(i<x){
            result+=horizontal[i]*verticalpieces;
            i++;
        }
        while(j<y){
            result+=vertical[j]*horizontalpieces;
            j++;
        }
        return result;
    }
};