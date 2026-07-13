class Solution {
public:
    vector<int>v;
    void find(int curr,int low,int high){
        if(curr>high) return;
        if(curr>=low && curr<=high) v.push_back(curr);
        if(curr>=123456789) return;
        if(curr==-1){
            for(int i=1;i<=9;i++){
                find(i,low,high);
            }
        }
        else{
            int neww=(curr%10)+1;
            if(neww!=10){
                int num=(curr*10)+neww;
                find(num,low,high);
            }

        }
    }
    vector<int> sequentialDigits(int low, int high) {
        find(-1,low,high);
        sort(v.begin(),v.end());
        return v;
    }
};