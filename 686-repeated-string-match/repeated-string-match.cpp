class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        string temp=a;
        int repeat=1;
        while(temp.length()<b.length()){
            temp+=a;
            repeat++;
        }
        if(temp.find(b)!=string::npos){
            return repeat;
        }
        if((temp+a).find(b)!=string::npos){
            return repeat+1;
        }
        return -1;
    }
};