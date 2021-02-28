import java.io.*;
import java.util.StringTokenizer;

public class grid {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solution.solve(in, out);
        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
        public int[] readArray(int n)
        {
            int[] arr=new int[n];
            for(int i=0;i<n;i++) arr[i]=nextInt();
            return arr;
        }
    }
}
class Solution
{
    public static void solve(grid.InputReader in, PrintWriter out)
    {
        long mod=(long)1e9+7;
        int h=in.nextInt();  //Height of cell
        int w=in.nextInt();  //Width of cell
        char[][] grid=new char[h][w];
        for(int i=0;i<h;i++)
        {
            String z=in.next();
            for(int j=0;j<w;j++)
                grid[i][j]=z.charAt(j);
        }
        if(grid[0][0]=='*')
            out.println(0);
        else
        {
            long[][] dp=new long[h][w];
            dp[0][0]=1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (grid[i][j] != '*') {
                        if (j - 1 >= 0)
                            dp[i][j] = dp[i][j] + dp[i][j - 1];
                        if (i - 1 >= 0)
                            dp[i][j] = dp[i][j] + dp[i - 1][j];
                        if (dp[i][j] >= mod)
                            dp[i][j] -= mod;
                    }
                }
            }
            out.println(dp[h - 1][w - 1]);
        }
    }
}