class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening=0;
        int closing=0;
        int n=s.length();
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') opening++;
            else closing++;

            if(closing>opening){
                count++;
                opening++;
            }
            if(i==n-1) count+=abs(opening-closing);
        }
        return count;
    }
};