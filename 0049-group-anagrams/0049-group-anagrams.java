class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList();
        HashMap<String, List<String>> mpp = new HashMap<>();
        for (String it : strs) {
            char[] current = it.toCharArray();
            Arrays.sort(current);
            String curr = new String(current);
            if (!mpp.containsKey(curr)) {
                // agar current wala mpa me nai hai toh add kar do the key, and an empty List as
                // value
                List<String> temp = new ArrayList();
                mpp.put(curr, temp);
            }

            // now here jo bhi string hoga, uska key pakka pakka hoga map me(due to the line
            // 9-13 thing)
            // so just get the current key ka value(by mpp.get(curr)) than add the current
            // element 'it' to it
            mpp.get(curr).add(it);

        }

        return new ArrayList<>(mpp.values());

    }
}