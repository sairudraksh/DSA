class Solution {
public:
    bool isperfectsquare(int z){
        int root=sqrt(z);
        if(root*root==z) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isperfectsquare(x) && isperfectsquare(y)){
                return true;
            }
            else if(!isperfectsquare(y)){
                y=(int)sqrt(y)*(int)sqrt(y);
                x=c-y;
            }
            else{
                x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
                y=c-x;
            }
        }
        return false;
    }
};