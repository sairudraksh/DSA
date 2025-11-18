class Solution {
public:
    unordered_map<char,string>map;
    vector<string>ans;
    void find(string &digits,int i,string &str){
        if(i>=digits.size()){
            ans.push_back(str);
            return;
        }
        string s=map[digits[i]];
        for(int l=0;l<s.length();l++){
            str+=s[l];
            find(digits,i+1,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="wxyz";
        string s="";
        find(digits,0,s);
        return ans;
    }
};