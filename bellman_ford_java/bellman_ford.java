import java.io.*;
import java.util.*;

public class bellman_ford {
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
    // Assuming no negative weight cycles
    public static void solve(bellman_ford.InputReader in, PrintWriter out)
    {
        System.out.println("Enter number of nodes");
        int n=in.nextInt();
        System.out.println("Enter number of edges");
        int m=in.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        ArrayList<Integer>[] cost = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
            cost[i] = new ArrayList<Integer>();
        }
        System.out.println("Enter edges in format: u , v, w");
        for(int i=0;i<m;i++)
        {
            int x=in.nextInt();
            int y=in.nextInt();
            int w=in.nextInt();
            adj[x].add(y);
            cost[x].add(w);
        }
        System.out.println("Enter source node");
        int x = in.nextInt();
        int[] dist=minDistance(adj,cost,x);
        System.out.println("Distance of other nodes from "+x);
        for(int i=0;i<dist.length;i++)
        {
            if(i!=x)
            out.print(dist[i]+" ");
        }
        out.println();
    }
    public static int[] minDistance(ArrayList<Integer>[] adj,ArrayList<Integer>[] cost,int s)
    {
        int[] dist=new int[adj.length];
        Arrays.fill(dist,Integer.MAX_VALUE);
        int[] prev=new int[adj.length];
        Arrays.fill(prev,-1);
        dist[s]=0;
        for(int i=0;i<adj.length-1;i++)
        {
            for(int j=0;j<adj.length;j++)
            {
                for(int k=0;k<adj[j].size();k++)
                {
                    Relax(j,adj[j].get(k),cost[j].get(k),dist,prev);
                }
            }
        }
        return dist;
    }
    public static void Relax(int u,int v,int w,int[]dist,int[] prev)
    {
        if(dist[v]>dist[u]+w)
        {
            dist[v]=dist[u]+w;
            prev[v]=u;
        }
    }
}