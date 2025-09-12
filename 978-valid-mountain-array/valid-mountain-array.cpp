class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(arr.size()<3) return false;
        for(int i=1;i<arr.size()-1;i++){
            bool isTrue=true;
            for(int j=0;j<i;j++){
                if(arr[j]>=arr[i]){
                    isTrue=false;
                    break;
                }
                else if(j!=0 && arr[j-1]>=arr[j]){
                    isTrue=false;
                    break;
                }
            }
            for(int k=i+1;k<n;k++){
                if(!isTrue) break;
                if(arr[k]>=arr[i]){
                    isTrue=false;
                    break;
                }
                else if(k!=i+1 && arr[k-1]<=arr[k]){
                    isTrue=false;
                    break;
                }
            }
            if(isTrue) return true;
        }
        return false;
    }
};