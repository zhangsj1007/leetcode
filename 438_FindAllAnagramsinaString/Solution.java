//date: 2016-12-14
//desc: left要走的路，right已经走一遍了，所以只有那些在p中的char才有可能>=0.

public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();
        int[] hash = new int[128];
        for (char c : p.toCharArray()){
            hash[c]++;
        }
        int left = 0;
        int right = 0;
        int count = p.length();
        while(right < s.length()){
            if (hash[s.charAt(right++)]-- >= 1) count--;
            if (count == 0) list.add(left);
            if (right - left == p.length() && hash[s.charAt(left++)]++ >= 0) count++;
        }
        return list;
    }
}
