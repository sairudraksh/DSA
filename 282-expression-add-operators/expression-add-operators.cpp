class Solution {
public:
    vector<string>ans;
    void find(string &num,int target,int idx,long long curr,long long last,string path){
        if(idx>=num.length()){
            if(curr==target) ans.push_back(path);
            return;
        }

        long long val=0;
        string s="";
        for(int i=idx;i<num.length();i++){
            if(i>idx && num[idx]=='0') break;
            val=val*10+(num[i]-'0');
            s+=num[i];
            if(idx==0){
                find(num,target,i+1,val,val,s);
            }
            else{
                find(num,target,i+1,curr+val,val,path+'+'+s);
                find(num,target,i+1,curr-val,-val,path+'-'+s);
                find(num,target,i+1,curr-last+(last*val),last*val,path+'*'+s);// remove last added and multiply current dou to Bodmas
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        find(num,target,0,0,0,"");
        return ans;
    }
};