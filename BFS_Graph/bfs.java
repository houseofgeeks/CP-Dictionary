import java.io.*;
import java.util.*;

public class bfs {
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
    /*
    The following code return distance of all nodes from a given node. 
    If there are no edges connecting a node from the "start node" the result will be -1.
    */
    public static void solve(bfs.InputReader in, PrintWriter out)
    {
        System.out.println("Enter the number of nodes");
        int n=in.nextInt();
        System.out.println("Enter the number of edges");
        int m=in.nextInt();
        ArrayList<Integer>[] adj=(ArrayList<Integer>[])new ArrayList[n];
        for(int i=0;i<n;i++)
        adj[i]=new ArrayList<>();
        System.out.println("Enter the edges");
        for(int i=0;i<m;i++)
        {
            int a=in.nextInt();
            int b=in.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        System.out.println("Enter the starting node");
        int start=in.nextInt();
        System.out.println("Nodes discovered in BFS order starting from "+start);
        BFS(adj,start);
    }
    public static void BFS(ArrayList<Integer>[] adj,int s)
    {
        boolean[] visit=new boolean[adj.length];
        LinkedList<Integer> Q=new LinkedList<>();
        visit[s]=true;
        Q.add(s);
        while(!Q.isEmpty())
        {
            int u=Q.poll();
            System.out.print(u+" ");
            for(int i=0;i<adj[u].size();i++)
            {
                if(!visit[adj[u].get(i)])
                {
                    Q.add(adj[u].get(i));
                    visit[adj[u].get(i)]=true;
                }
            }
        }
        System.out.println();
    }
}