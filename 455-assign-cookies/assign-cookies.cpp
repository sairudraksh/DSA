class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& size) {
        sort(greed.begin(),greed.end());
        sort(size.begin(),size.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<greed.size() && j<size.size()){
            if(greed[i]<=size[j]){
                count++;
                i++;
                j++;
            }
            else j++;
        } 
        return count;
    }
};