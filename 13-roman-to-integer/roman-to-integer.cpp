class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map;
        int n=s.length();
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        int count=0;
        for(int i=0;i<=s.length()-1;i++){
            if(i==n-1){
                count+=map[s[i]];
            }
            else if(s[i]=='I'){
                if(s[i+1]=='V'){
                    count+=4;
                    i++;
                }
                else if(s[i+1]=='X'){
                    count+=9;
                    i++;
                }
                else count+=map[s[i]];
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    count+=40;
                    i++;
                }
                else if(s[i+1]=='C'){
                    count+=90;
                    i++;
                }
                else count+=map[s[i]];
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    count+=400;
                    i++;
                }
                else if(s[i+1]=='M'){
                    count+=900;
                    i++;
                }
                else count+=map[s[i]];
            }
            else count+=map[s[i]];
        }
        return count;
    }
};