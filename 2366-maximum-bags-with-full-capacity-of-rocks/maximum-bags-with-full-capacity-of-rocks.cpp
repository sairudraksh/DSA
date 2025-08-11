class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int total) {
        int n=rocks.size();
        vector<int>diff;
        int count=0;
        for(int i=0;i<n;i++){
            int a=capacity[i]-rocks[i];
            if(a==0) count++;
            else diff.push_back(a);
        }

        if(diff.size()==0) return count;
        sort(diff.begin(),diff.end());

        for(int i=0;i<diff.size();i++){
            if(total>=diff[i]){
                count++;
                total-=diff[i];
            }
            else break;
        }
        return count;
    }
};