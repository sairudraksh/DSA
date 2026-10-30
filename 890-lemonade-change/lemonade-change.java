class Solution {
    public boolean lemonadeChange(int[] bills) {
        HashMap<Integer,Integer>map=new HashMap<>();

        int n=bills.length;


        for(int i=0;i<n;i++){
            if(bills[i]==5){
                map.put(bills[i],map.getOrDefault(bills[i],0)+1);
            }
            else if(bills[i]==10){
                if(map.getOrDefault(5,0)>0){
                    map.put(bills[i],map.getOrDefault(bills[i],0)+1);
                    map.put(5,map.getOrDefault(5,0)-1);
                }
                else return false;
            }
            else{
                if(map.getOrDefault(5,0)>0 && map.getOrDefault(10,0)>0){
                    map.put(bills[i],map.getOrDefault(bills[i],0)+1);
                    map.put(5,map.getOrDefault(5,0)-1);
                    map.put(10,map.getOrDefault(10,0)-1);
                }
                else if(map.getOrDefault(5,0)>=3){
                    map.put(5,map.getOrDefault(5,0)-3);
                    map.put(bills[i],map.getOrDefault(bills[i],0)+1);
                }
                else return false;
            }
        }

        return true;

    }
}