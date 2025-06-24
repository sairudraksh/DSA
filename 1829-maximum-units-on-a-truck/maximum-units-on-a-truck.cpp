bool cmp(vector<int>&v1 ,vector<int>&v2){
    return v1[1]>v2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int trucksize) {
        sort(v.begin(),v.end(),cmp);
        int profit=0;
        for(int i=0;i<v.size();i++){//row size
            if(trucksize>=v[i][0]){
                profit+=v[i][0]*v[i][1];
                trucksize-=v[i][0];
            }
            else{
                profit+=trucksize*v[i][1];
                trucksize=0;
            }
            if(trucksize==0) break;
        }
        return profit;
    }
};