class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            int num=(int)s[i];
            if((num >= 48 && num <= 57) || (num>=65 && num<=90) || (num>=97 && num<=122)){// 48 to 57 are 0 to 9
                if(num>=65 && num<=91){
                    num=num+32;
                    char ch=char(num);
                    ans+=ch;
                }
                else ans+=s[i];
            }
        }
        int i=0;
        int j=ans.length()-1;
        while(i<=j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
