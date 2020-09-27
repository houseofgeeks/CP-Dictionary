// Leetcode: https://leetcode.com/problems/longest-palindromic-substring/

// Reference(Wikipedia): https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm

// Reference(GeeksForGeeks): 
// Part1: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
// Part2: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-2/
// Part3: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-3-2/
// Part4: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4/?ref=rp


import java.util.Arrays;

public class LongestPalindromicSubstring {

    public static String longestPalindrome(String s) {
        if (s==null || s.isEmpty())
            return "";
        
        char[] s2 = addBoundaries(s.toCharArray());

        // Creating p[] to store the lengths of the 
        // palindrome for each center point in s
        // (initially all 0s).
        int[] p = new int[s2.length]; 

        // s2.length = p.length = 2 * s.length() + 1

        // Track the following pointers (referencing indices in p[] and s2[]).
        // r -> the next element to be examined (initially 0).
        // c -> the largest/left-most palindrome whose right boundary is r - 1 (initially 0).
        // i -> the next palindrome to be calculated (initially 1).
        // m -> character candidate for comparing with r. Computed implicitly as: m = i*2-n, where n = r+1.
        // i2 -> the palindrome mirroring i from c. Computed implicitly as: i2 = c*2-i.

        int c = 0, r = 0; // Here the first element in s2 has been processed.
        int m = 0, n = 0; // The walking indices to compare if two elements are the same.
        for (int i = 1; i<s2.length; i++) {
            if (i>r) {
                p[i] = 0; m = i-1; n = i+1;
            } else {
                int i2 = c*2-i;
                if (p[i2]<(r-i-1)) {
                    p[i] = p[i2];
                    m = -1; // This signals bypassing the while loop below. 
                } else {
                    p[i] = r-i;
                    n = r+1; m = i*2-n;
                }
            }
            while (m>=0 && n<s2.length && s2[m]==s2[n]) {
                p[i]++; m--; n++;
            }
            if ((i+p[i])>r) {
                c = i; r = i+p[i];
            }
        }
        int len = 0; c = 0;
        for (int i = 1; i<s2.length; i++) {
            if (len<p[i]) {
                len = p[i]; c = i;
            }
        }
        char[] ss = Arrays.copyOfRange(s2, c-len, c+len+1);
        return String.valueOf(removeBoundaries(ss));
    }
    
    // Given a string in the form of a char array cs[], 
    // generate cs2[] by inserting a bogus character ('|')
    // between each character in cs[] (including outer boundaries).
    private static char[] addBoundaries(char[] cs) {
        if (cs==null || cs.length==0)
            return "||".toCharArray();

        char[] cs2 = new char[cs.length*2+1];
        for (int i = 0; i<(cs2.length-1); i = i+2) {
            cs2[i] = '|';
            cs2[i+1] = cs[i/2];
        }
        cs2[cs2.length-1] = '|';
        return cs2;
    }

    private static char[] removeBoundaries(char[] cs) {
        if (cs==null || cs.length<3)
            return "".toCharArray();

        char[] cs2 = new char[(cs.length-1)/2];
        for (int i = 0; i<cs2.length; i++) {
            cs2[i] = cs[i*2+1];
        }
        return cs2;
    }   

    public static void main(String[] args) {
         
         String s = "babad";
         System.out.println(longestPalindrome(s));
     } 
}