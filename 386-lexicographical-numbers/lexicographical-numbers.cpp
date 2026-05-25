class Solution {
public:
    void find(int curr,int n,vector<int>&v){
        if(curr>n) return;
        if(curr!=0) v.push_back(curr);
        for(int i=0;i<=9;i++){

            int num=curr*10+i;
            if(num==0) continue;
            find(num,n,v);

        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        find(0,n,v);
        return v;
    }
};