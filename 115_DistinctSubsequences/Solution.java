public class Solution {
    public int numDistinct(String s, String t) {
        int[][] record = new int[t.length()+1][s.length()+1];
        for (int i = 0; i <= s.length(); i++){
            record[0][i] = 1;
        }
        for (int i = 0; i < t.length(); i++){
            for (int j = 0; j < s.length(); j++){
                if (t.charAt(i) == s.charAt(j)){
                    record[i+1][j+1] = record[i+1][j] + record[i][j];  
                }else{
                    record[i+1][j+1] = record[i+1][j];
                }
            }
        }
        return record[t.length()][s.length()];
    }
}
