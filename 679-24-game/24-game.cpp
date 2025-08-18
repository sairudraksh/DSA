class Solution {//double result = 4.0 / (1.0 - 2.0 / 3.0);
public:
    double esp=0.1;
    bool solve(vector<double>&nums){
        int n=nums.size();
        if(nums.size()==1){
            if(abs(nums[0]-24)<=esp) return true;
            else return false;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;

                vector<double>v;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    v.push_back(nums[k]);
                }
                double a=nums[i];
                double b=nums[j];

                vector<double>possibilities={a+b,a-b,b-a,a*b};
                if(abs(a)>0.0) possibilities.push_back(b/a);
                if(abs(b)>0.0) possibilities.push_back(a/b);

                for(int i=0;i<possibilities.size();i++){
                    v.push_back(possibilities[i]);
                    if(solve(v)) return true;
                    v.pop_back();
                }

            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        int n=cards.size();
        vector<double>nums;
        for(int i=0;i<n;i++){
            nums.push_back(1.0*cards[i]);
        }
        return solve(nums);
    }
};