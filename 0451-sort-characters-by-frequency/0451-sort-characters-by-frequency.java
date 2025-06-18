class Solution {
    public String frequencySort(String s) {

        // freq bana lo
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            int currentFreq = freqMap.getOrDefault(c, 0); 
            freqMap.put(c, currentFreq + 1);
        }

        PriorityQueue<Map.Entry<Character, Integer>> pq = 
            new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());

        // saare map se pq me daalo
        pq.addAll(freqMap.entrySet());

        // ans wali string banao
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            char alphabet = entry.getKey();
            int freq = entry.getValue();

            for (int i = 0; i < freq; i++) {
                ans.append(alphabet);
            }
        }

        return ans.toString();
    }
}