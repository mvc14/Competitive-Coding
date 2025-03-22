class LongestSubset {

    // using set sliding window (O(n^2))
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int left = 0, max = 0;

        for (int right = 0; right < s.length(); right++) {

            while (set.contains(s.charAt(right))) {
                set.remove(s.charAt(left));
                left++;
            }

            set.add(s.charAt(right));
            max = Math.max(max, right - left + 1);
        }
        return max;
    }

    // optimized solution
    int max = 0, n = s.length();
    Map<Character, Integer> map = new HashMap<>();
        for (int j = 0, i = 0; j < n; j++) {

        if (map.containsKey(s.charAt(j))) {
            i = Math.max(map.get(s.charAt(j)), i);
        }
        max = Math.max(max, j - i +1);
        map.put(s.charAt(j), j + 1);
    }
}
