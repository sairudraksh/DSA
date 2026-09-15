class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character,Integer>map=new HashMap<>();

        int n=s.length();

        for(int i=0;i<n;i++){
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        int evenCount=0;
        int oddCount=0;
        int num1=0;
        for(Character x:map.keySet()){
            int num=map.getOrDefault(x,0);
            if(num%2==0){
                evenCount+=num;
            }
            else if(num==1){
                num1++;
            }
            else if(num%2!=0){
                num1++;
                oddCount+=(num-1);
            }
            else oddCount+=(num-1);
        }
        if(num1>0){
            return evenCount+1+oddCount;
        }
        else return evenCount+oddCount;
    }
}