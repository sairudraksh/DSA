class Solution {
public:
    string find(string s){
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') s[i]='0';
            else if(s[i]=='0') s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";

        for(int i=2;i<=n;i++){
            string reverseBit=find(s);

            s+="1";

            s+=reverseBit;
        }

        for(int i=0;i<s.length();i++){
            if(i+1==k) return s[i];
        }
        return ' ';
    }
};