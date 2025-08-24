class Solution {
public:
    unordered_map<char,string>map;
    vector<string>finalans;
    void find(string &digits,string &s,int i){
        if(i>=digits.length()){
            finalans.push_back(s);
            return;
        }
        string str=map[digits[i]];

        for(int k=0;k<str.length();k++){
            s+=str[k];
            find(digits,s,i+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return finalans;
        }
        string s="";
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="wxyz";
        find(digits,s,0);
        return finalans;        
    }
};