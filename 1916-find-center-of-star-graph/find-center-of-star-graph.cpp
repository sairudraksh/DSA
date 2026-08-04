class Solution {
public:
    int findCenter(vector<vector<int>>& edge) {
        int a=edge[0][0];
        int b=edge[0][1];

        int c=edge[1][0];
        int d=edge[1][1];

        return (a==c || a==d) ? a : b;
    }
};