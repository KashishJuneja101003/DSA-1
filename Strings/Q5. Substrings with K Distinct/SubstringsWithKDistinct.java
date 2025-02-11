import java.util.*;

class SubstringsWithKDistinct {
    public int countSubstr(String s, int k) {
        if (k == 0) return 0;
        return atMostK(s, k) - atMostK(s, k - 1);
    }

    private int atMostK(String s, int k) {
        int left = 0, count = 0;
        Map<Character, Integer> freq = new HashMap<>();

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
            
            while (freq.size() > k) { // Shrink window if more than k distinct chars
                char leftChar = s.charAt(left);
                freq.put(leftChar, freq.get(leftChar) - 1);
                if (freq.get(leftChar) == 0) {
                    freq.remove(leftChar);
                }
                left++;
            }
            count += (right - left + 1); // Count valid substrings
        }
        return count;
    }

    public static void main(String[] args) {
        SubstringsWithKDistinct sol = new SubstringsWithKDistinct();
        System.out.println(sol.countSubstr("aba", 2));      // Output: 3
        System.out.println(sol.countSubstr("abaaca", 1));   // Output: 7
        System.out.println(sol.countSubstr("cdad", 4));     // Output: 0
    }
}
