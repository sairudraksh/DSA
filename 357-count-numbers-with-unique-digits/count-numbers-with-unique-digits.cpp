class Solution {
public:
    int find(int &targetlen,unordered_set<int>&set){
        if(set.size()==targetlen) return 1;
        int sum=0;
        for(int i=0;i<=9;i++){
            if(set.find(i)==set.end()){
                if(i==0 && set.size()==0) continue;

                set.insert(i);
                sum+=find(targetlen,set);
                set.erase(i);
            }
        }
        return sum;
    }
    int countNumbersWithUniqueDigits(int n) {
        int count=1;

        for(int i=1;i<=n;i++){
            unordered_set<int>set;
            count+=find(i,set);
        }
        return count;
    }
};