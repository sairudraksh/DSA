class Solution {
public:
    int M=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<int>widths;
        unordered_set<int>heights;

        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int width=vFences[j]-vFences[i];
                widths.insert(width);
            }
        }
        int maxSide=0;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                int height=hFences[j]-hFences[i];
                if(widths.find(height)!=widths.end()){
                    maxSide=max(maxSide,height);
                }
            }
        }
        if(maxSide==0) return -1;
        return (1LL*maxSide*maxSide)%M;
    }
};