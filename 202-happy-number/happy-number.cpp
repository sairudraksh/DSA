class Solution {
public:
    unordered_set<int>st;
    int digits(int n){
        int sum=0;
        while(n>0){
            int num=n%10;
            num=num*num;
            sum+=num;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum=digits(n);
        if(st.find(sum)!=st.end()) return false;
        else if(sum==1) return true;
        st.insert(sum);
        return isHappy(sum);
    }
};