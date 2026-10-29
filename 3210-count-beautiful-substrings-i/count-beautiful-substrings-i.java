class Solution {
    public int beautifulSubstrings(String s, int k) {
        int n=s.length();
   
        int[] vovel=new int[n];
       
        int[] consonent=new int[n];
        for(int i=0;i<n;i++){
            vovel[i]=0;
            consonent[i]=0;
        }
        if(s.charAt(0)=='a' ||s.charAt(0)=='e' ||s.charAt(0)=='i' ||s.charAt(0)=='o' ||s.charAt(0)=='u'){
            vovel[0]=1;
        }
        else consonent[0]=1;
        for(int i=1;i<n;i++){
            if(s.charAt(i)=='a' ||s.charAt(i)=='e' ||s.charAt(i)=='i' ||s.charAt(i)=='o' ||s.charAt(i)=='u'){
                vovel[i]=vovel[i-1]+1;
                consonent[i]=consonent[i-1];
            }
            else{
                consonent[i]=consonent[i-1]+1;
                vovel[i]=vovel[i-1];
            }
        }
        int curr=0;
        for(int i=0;i<n;i++){
            int count1=0;
            int count2=0;
            for(int j=i;j<n;j++){
                if(s.charAt(j)=='a' ||s.charAt(j)=='e' ||s.charAt(j)=='i' ||s.charAt(j)=='o' ||s.charAt(j)=='u'){
                    count1++;
                }
                else count2++;

                if(count1==count2 && (count1*count2)%k==0) curr++;
            }
        }
        return curr;
    }
}