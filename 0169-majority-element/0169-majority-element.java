class Solution {
    public int majorityElement(int[] nums) {
        int length=nums.length,reqd_freq=length/2;
        HashMap<Integer,Integer> mpp=new HashMap<>();
        for(int it:nums){
            if(mpp.containsKey(it)){
                int currfreq=mpp.get(it);
                currfreq++;
                mpp.put(it,currfreq);
            }
            else{
                mpp.put(it,1);
            }
        }

        // iterate over the map
        for(Integer keys:mpp.keySet()){
            if(mpp.get(keys)>reqd_freq){
                return keys;
            }
        }

        return -1;
    }
}