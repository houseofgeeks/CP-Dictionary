import java.io.*;
import java.util.StringTokenizer;

public class kadane {
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
    public static void solve(kadane.InputReader in,PrintWriter out)
    {
        System.out.println("Enter size of array");
        int n=in.nextInt();
        System.out.println("Enter elements of array");
        int[] arr=in.readArray(n);
        out.println("Maximum Subarray sum ="+sum(arr));
    }

    public static int sum(int[] arr)
    {
        int len=arr.length;
        int max=Integer.MIN_VALUE;
        int sum=0;
        for(int i=0;i<len;i++)
        {
            sum+=arr[i];
            max=Math.max(max,sum);
            if(sum<0)
            sum=0;    
        }
        return max;
    }
}