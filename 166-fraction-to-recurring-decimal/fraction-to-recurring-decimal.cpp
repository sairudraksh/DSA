class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        long long numerator=num;
        long long denominator=deno;
        string result="";
        if(numerator==0 || denominator==0) return "0";
        if(numerator<0 && denominator<0){
            numerator=numerator*-1;
            denominator=denominator*-1;
        }

        else if(numerator<0 || denominator<0){
            if(numerator<0) numerator=numerator*-1;
            if(denominator<0) denominator=denominator*-1;
            result+='-';
        }
        long long remainder=numerator%denominator;

        long long ans=numerator/denominator;
        string ans2=to_string(ans);

        result+=ans2;

        if(remainder==0){
            return result;
        }
        else{
            result+='.';
        }


        unordered_map<long,int>map;
        
        remainder=remainder*10;
        while(remainder!=0){
            if(map.find(remainder)!=map.end()){
                int idx=map[remainder];

                result.insert(idx, "(");
                result+=')';
                return result;

            }

            if(map.find(remainder)==map.end()) map[remainder]=result.length();
            ans=(remainder/denominator);
            ans2=to_string(ans);

            result=result+ans2;
        
            remainder=remainder%denominator;
            remainder=remainder*10;
        }
        return result;
    }
};