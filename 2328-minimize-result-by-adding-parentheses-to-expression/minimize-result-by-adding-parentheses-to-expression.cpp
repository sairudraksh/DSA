class Solution {
public:
    int n;
    string ans;
    int maximum;
    string formString(string &s,int &l,int &p){
        string s1="";
        for(int i=0;i<s.length();i++){
            if(i==l){
                s1+='(';
                s1+=s[i];
            }
            else if(i==p){
                s1+=s[i];
                s1+=')';
            }
            else{
                s1+=s[i];
            }
        }
        return s1;
    }
    void find(string &s,int i,int j,int mul1,int mul2){
        if(s[i]=='+' || s[j]=='+') return ;

        int curradd1=0;
        int curradd2=0;

        int l=i;
        while(s[l]!='+'){
            curradd1=(curradd1*10)+(s[l]-'0');
            l++;
        }
        l++;

        while(l!=j+1){
            curradd2=(curradd2*10)+(s[l]-'0');
            l++;
        }
        int currmul1=1;
        int currmul2=1;
        if(mul1!=0){
            currmul1=mul1;
        }
        if(mul2!=0){
            currmul2=mul2;
        }
        long long total=curradd1+curradd2;
        long long final=currmul1*total;
        long long final2=final*currmul2;

        if(s[i+1]!='+'){
            int currmul=mul1*10+(s[i]-'0');
            find(s,i+1,j,currmul,mul2);
        }

        if(s[j-1]!='+'){
            int len=s.length()-j;
            int len2=1;
            for(int t=0;t<len-1;t++){
                len2=len2*10;
            }
            int currmul=((s[j]-'0')*len2)+mul2;
            find(s,i,j-1,mul1,currmul);
        }

        if(final2<maximum){
            maximum=final2;
            ans=formString(s,i,j);
        }

    }
    string minimizeResult(string s) {
        n=s.length();
        maximum=INT_MAX;
        ans="";
        find(s,0,n-1,0,0);
        return ans;
    }
};