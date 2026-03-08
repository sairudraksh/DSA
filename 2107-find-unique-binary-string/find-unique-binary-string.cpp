class Solution {
public:
    string ans="";
    unordered_map<string,int>map;
    int n;
    void find(string s){
        if(s.length()==n){
            if(map.find(s)==map.end()){
                ans=s;
            }
            return ;
        }
        s+="0";
        find(s);
        s.pop_back();
        s+="1";
        find(s);
        s.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        string s="";
        find(s);
        return ans;
    }
};