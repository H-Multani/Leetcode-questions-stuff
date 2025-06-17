class Solution {
    public boolean lemonadeChange(int[] b) {
        if(b[0]!=5) return false;

        int five=0,ten=0,twenty=0;

        for(int curr:b){
            if(curr==5){
                five++;
            }
            else if(curr==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                // note mila h 20 ka
                // change=15
                if(ten>0 && five>0){
                    ten--;
                    five--;
                    twenty++;
                }
                else if(five>=3){
                    five--;
                    five--;
                    five--;
                }
                else return false;
            }
        }

        return true;
    }
}