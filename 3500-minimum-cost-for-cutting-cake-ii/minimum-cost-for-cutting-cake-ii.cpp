class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontal, vector<int>& vertical) {
        sort(horizontal.begin(), horizontal.end(), greater<int>());
        sort(vertical.begin(), vertical.end(), greater<int>());
        int x=horizontal.size();
        int y=vertical.size();

        int i=0;
        int j=0;

        long long horizontalpieces=1;
        long long verticalpieces=1;

        long long result=0;

        while(i<x && j<y){
            if(horizontal[i]>=vertical[j]){
                result+=(long long)horizontal[i]*verticalpieces;
                horizontalpieces++;
                i++;
            }
            else{
                result+=(long long)vertical[j]*horizontalpieces;
                verticalpieces++;
                j++;
            }
        }
        while(i<x){
            result+=(long long)horizontal[i]*verticalpieces;
            i++;
        }
        while(j<y){
            result+=(long long)vertical[j]*horizontalpieces;
            j++;
        }
        return result;
    }
};