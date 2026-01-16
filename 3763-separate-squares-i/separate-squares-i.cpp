class Solution {
public:
    bool check(vector<vector<int>>& squares,double result,double mid){
        double bot_area=0;
        for(auto &square: squares){
            double y=square[1];
            double l=square[2];

            double boty=y;
            double topy=y+l;

            if(mid>=topy){
                bot_area+=l*l;
            }
            else if(mid>boty){
                bot_area+=(mid-boty)*l;
            }
        }
        return bot_area>=result/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low=INT_MAX;
        double high=INT_MIN;

        double result=0.00000;

        for(auto &square : squares){
            double l=square[2];
            double x=square[0];
            double y=square[1];

            result+=l*l;

            low=min(low,y);
            high=max(high,y+l);
        }
        double ans=0.00000;
        while(high-low>1e-5){
            double mid=low+(high-low)/2;

            ans=mid;

            if(check(squares,result,mid)){
                high=mid;
            }
            else low=mid;
        }
        return ans;
    }
};