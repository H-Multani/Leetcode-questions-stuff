class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer> mpp=new HashMap<>();

        for(int i:nums){
            mpp.put(i,mpp.getOrDefault(i,0)+1);
        }

        ArrayList<Integer>[] bucket=new ArrayList[n+1];
        for(int i=0;i<n+1;i++){
            bucket[i]=new ArrayList<>();
        }

        for(Map.Entry<Integer,Integer> curr:mpp.entrySet()){
            int element=curr.getKey();
            int freq=curr.getValue();

            bucket[freq].add(element);

        }

        int[] ans=new int[k];
        int j=0;
        for(int i=n;i>=0 && j<k;i--){
            if(bucket[i].size()==0) continue;

            for(int it:bucket[i]){
                ans[j]=it;
                j++;

                if(j>=k) break;
            }

        }

        return ans;
    }
}