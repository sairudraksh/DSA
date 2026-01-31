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
       
        int a=0;
        int b=0;

        string org=str;

        str+=s[i];
        a=find(s,str,i+1,map);
        
        if(map.find(str)==map.end()){
            map[org+s[i]]++;
            str="";
            b=find(s,str,i+1,map);
            map.erase(org+s[i]);
            str=org;
        }
        return max(a,b);
    }
    int maxUniqueSplit(string s) {
        n=s.length();
        string str="";
        unordered_map<string,int>map;
        return find(s,str,0,map);
    }
}; 