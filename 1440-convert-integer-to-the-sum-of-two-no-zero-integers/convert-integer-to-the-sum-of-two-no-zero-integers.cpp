class Solution {
public:
    bool isValid(int n){
        while(n>0){
            int num=n%10;
            if(num==0) return false;
            n=n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a=0;
        int b=0;

        vector<int>result;

        for(int i=1;i<n;i++){
            a=n-i;
            b=i;
            if(isValid(a) && isValid(b)){
                result.push_back(a);
                result.push_back(b);
                break;
            }
        }

        return result;
    }
};