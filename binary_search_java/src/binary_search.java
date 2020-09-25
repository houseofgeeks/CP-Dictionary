import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class binary_search {
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
    public static void solve(binary_search.InputReader in, PrintWriter out)
    {
        System.out.println("Enter the size of array");
        int n=in.nextInt();
        System.out.println("Enter the elements of array");
        int[] arr=in.readArray(n);
        boolean isSorted=checkSort(arr);
        if(isSorted){
            Arrays.sort(arr);
            System.out.println("Enter the element to be searched");
            int ele=in.nextInt();
            int pos=BinarySearch(arr,ele);
            out.println(pos);
        }
        else
        out.println("Array not Sorted");
    }
    public static boolean checkSort(int[] arr)
    {
        boolean res=true;
        boolean res2=true;
        for(int i=0;i<arr.length-1;i++){
            if(arr[i]>arr[i+1])
            {
                res=false;
                break;
            }
        }
        for(int i=0;i<arr.length-1;i++){
            if(arr[i]<arr[i+1])
            {
                res2=false;
                break;
            }
        }
        return res||res2;
    }
    public static int BinarySearch(int[] arr, int ele)
    {
        int high=arr.length-1;
        int low=0;
        while(high>=low)
        {
            int mid=(high+low)/2;
            if(arr[mid]==ele)
                return mid;
            if(arr[mid]>ele)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
}