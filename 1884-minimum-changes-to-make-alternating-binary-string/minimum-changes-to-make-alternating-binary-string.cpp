class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        bool take=false;

        string s1="";
        string s2="";

        for(int i=0;i<n;i++){
            if(take==false){
                s1+='0';
                s2+='1';
                take=true;
            }
            else{
                s1+='1';
                s2+='0';
                take=false;
            }
        }
        int count1=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s[i]) count1++;
        }
        int count2=0;
        for(int i=0;i<s2.length();i++){
            if(s2[i]!=s[i]) count2++;
        }
        return min(count1,count2);
    }
};