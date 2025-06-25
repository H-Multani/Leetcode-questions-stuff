class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] prefix=new int[1002];

        for(int[] currtrip:trips){
            int passenger=currtrip[0];
            int currstart=currtrip[1];
            int currend=currtrip[2];

            prefix[currstart]+=passenger;
            prefix[currend]-=passenger;
        }

        for(int i=1;i<1002;i++){
            prefix[i]+=prefix[i-1];
        }

        // prefix[i]=4 meaning-> i th pt par 4 passenger baithe hai
        for(int it:prefix){
            if(it>capacity) return false;
        }
        return true;

    }
}