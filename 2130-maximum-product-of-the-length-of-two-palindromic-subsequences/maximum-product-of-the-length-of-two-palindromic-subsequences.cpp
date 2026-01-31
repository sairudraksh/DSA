class Solution{
public:
    int maximum=0;
    int n;
    bool isPalindrome(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void find(string &s,string &a,string &b,int i){
        if(i>=n){
            if(isPalindrome(a) && isPalindrome(b)){
                int len=a.length()*b.length();
                maximum=max(maximum,len);
            }
            return;
        }
        a+=s[i];
        find(s,a,b,i+1);
        a.pop_back();

        b+=s[i];
        find(s,a,b,i+1);
        b.pop_back();

        find(s,a,b,i+1);
    }
    int maxProduct(string s){
        n=s.length();
        string str1="";
        string str2="";
        find(s,str1,str2,0);
        return maximum;
    }
};