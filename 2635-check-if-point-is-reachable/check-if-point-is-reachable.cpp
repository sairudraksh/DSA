class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        while(targetX>0 && targetY>0){
            if(targetX==1 && targetY==1) return true;

            if(targetX%2==0){
                targetX/=2;
            }

            else if(targetY%2==0){
                targetY/=2;
            }
            else if(targetX>targetY){
                targetX-=targetY;
            }
            else{
                targetY-=targetX;
            }
        }
        return false;
    }
};