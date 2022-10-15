public class Rabin_karp {
    public final static int d = 10;
    static void search(String pattern, String str, int q) {
      int m = pattern.length();
      int n = str.length();
      int i, j;
      int p = 0;
      int t = 0;
      int h = 1;
  
      for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
      // Calculate hash value for pattern and text
      for (i = 0; i < m; i++) {
        p = (d * p + pattern.charAt(i)) % q;
        t = (d * t + str.charAt(i)) % q;
      }
  
      // Find the match
      for (i = 0; i <= n - m; i++) {
        if (p == t) {
          for (j = 0; j < m; j++) {
            if (str.charAt(i + j) != pattern.charAt(j))
              break;
          }
          if (j == m)
            System.out.println("Pattern is found at position: " + (i + 1));
        }
  
        if (i < n - m) {
          t = (d * (t - str.charAt(i) * h) + str.charAt(i + m)) % q;
          if (t < 0)
            t = (t + q);
        }
      }
    }
    public static void main(String[] args) {
      String str = "ABCCDDAEFG";
      String pattern = "CDD";
      int q = 13;
      search(pattern, str, q);
    }
  }