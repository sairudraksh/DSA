class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;

        int n=A.size();
        int m=B.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            map1[A[i]]++;
            map2[B[i]]++;
            int count=0;
            for(auto x:map1){
                if(map2.find(x.first)!=map2.end()){
                    count++;
                }
            }

            ans.push_back(count);

        }

        return ans;
    }
};