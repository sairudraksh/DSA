class Solution {
public:
    int commonFactors(int a, int b) {
        int z=min(a,b);
        int y=max(a,b);
        int count=0;
        for(int i=1;i<z;i++){
            if(a%i==0 && b%i==0){
                count++;
            }
        }
        if(y%z==0) count ++;
        return count;
    }
};