import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class rabinkarp {
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
    public static void solve(rabinkarp.InputReader in,PrintWriter out)
    {
        System.out.println("Enter the String");
        String T=in.next();
        System.out.println("Enter the String to be searched");
        String P=in.next();
        ArrayList<Integer> startIndex=new ArrayList<>();
        RabinKarp(T,P,startIndex);
        out.println("Starting indices in T from where P begins");
        out.println(startIndex);
    }

    //function for implementing RabinKarp
    public static void RabinKarp(String T,String P,ArrayList<Integer> startIndex)
    {
        int Tlen=T.length();
        int Plen=P.length();
        long p=(long)1e9+7;
        long x=(long)(Math.random()*(double)p);
        long pHash=PolyHash(P, p, x);
        long[] H=PreComputeHash(T, Plen, p, x);
        for(int i=0;i<Tlen-Plen+1;i++)
        {
            if(pHash!=H[i])
            continue;
            if(AreEqual(T.substring(i,i+Plen),P)){
            startIndex.add(i);
            }
        }
    }

    //function for executing Polynolmial Hashing
    public static long PolyHash(String s,long p,long x)
    {
        long hash=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            hash=(hash*x+s.charAt(i))%p;
        }
        return hash;
    }

    //function for checking, if the substring and the given string to be searched are equal if they have same hash value
    public static boolean AreEqual(String a,String b)
    {
        int len =a.length();
        for(int i=0;i<len;i++)
        {
            if(a.charAt(i)!=b.charAt(i))
            return false;
        }
        return true;
    }

    //function for precomputing hash values of all the substrings of "T" of size equal to the length of the string to be searched
    public static long[] PreComputeHash(String T,int Plen,long p,long x)
    {
        int Tlen=T.length();
        long[] H=new long[Tlen-Plen+1];
        String s=T.substring(Tlen-Plen, Tlen);
        H[Tlen-Plen]=PolyHash(s, p, x);
        long y=1;
        for(int i=1;i<=Plen;i++)
        {
            y=(y*x)%p;
        }
        for(int i=Tlen-Plen-1;i>=0;i--)
        {
            H[i]=(x*H[i+1]+T.charAt(i)-y*T.charAt(i+Plen))%p;
        }
        return H;
    }
}