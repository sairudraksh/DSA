class Solution {
public:
    int i=0;
    int calculate(string &s) {
        long long num=0;
        int sign=1;
        long long result=0;
        while(i<s.length()){
            char ch=s[i];

            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch=='-'){
                result+=sign*num;
                num=0;
                sign=-1;
            }
            else if(ch=='+'){
                result+=sign*num;
                num=0;
                sign=1;
            }
            else if(ch=='('){
                i++;
                num=calculate(s);
            }
            else if(ch==')'){
                return result+=sign*num;
            }
            i++;
        }
        result+=sign*num;
        return result;
    }
};