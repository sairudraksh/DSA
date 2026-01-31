class Solution {
public:
    int n;
    int find(string &s,string &str,int i,unordered_map<string,int>&map){
        if(i>=s.length()){
            if(str.length()>0){
                if(map.find(str)!=map.end()) return 0;
                else return map.size()+1;
            }
            return map.size();
        }
        str+=s[i];
        int a=0;
        int b=0;
        a=find(s,str,i+1,map);

        if(!str.empty() && !map.count(str)){
            string newstr=str;
            map[newstr]++;
            str="";
            b=find(s,str,i+1,map);
            str=newstr;
            map.erase(str);
        }
        str.pop_back();
        return max(a,b);
    }
    int maxUniqueSplit(string s) {
        n=s.length();
        string str="";
        unordered_map<string,int>map;
        return find(s,str,0,map);
    }
};