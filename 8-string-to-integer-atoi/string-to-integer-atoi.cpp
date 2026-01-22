class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long res=0;

        while(i<s.length() && s[i]==' ') i++;
        if(i>=s.length()) return 0;

        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        for(int j=i;j<s.length();j++){
            if(isdigit(s[j])){
                res=res*10+(s[j]-'0');
                if(sign*res<INT_MIN) return INT_MIN;
                if(sign*res>INT_MAX) return INT_MAX;
            }
            else break;
        }

        return (int)sign*res;
    }
};