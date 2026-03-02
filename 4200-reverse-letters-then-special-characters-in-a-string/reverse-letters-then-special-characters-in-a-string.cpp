class Solution {
public:
    string reverseByType(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<=j){
            if(int(s[i])<97 || int(s[i])>122){
                i++;
            }
            else if(int(s[j])<97 || int(s[j])>122){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        i=0;
        j=n-1;

        while(i<=j){
            if(int(s[i])>=97 && int(s[i])<=122){
                i++;
            }
            else if(int(s[j])>=97 && int(s[j])<=122){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};