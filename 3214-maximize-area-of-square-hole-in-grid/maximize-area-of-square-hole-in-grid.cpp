class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int currH=1;
        int currV=1;

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int count=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                count++;
            }
            else count=1;
            currH=max(currH,count);
        }
        count=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                count++;
            }
            else count=1;
            currV=max(currV,count);
        }

        int side=min(currV,currH)+1;
        return side*side;
    }
};