class Solution {
public:
    int maxContainers(int n, int w, int wt) {
        return min(wt/w,n*n);
    }
};