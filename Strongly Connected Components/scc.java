import java.io.*;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

// Input/Output
public class scc {
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

// Logic
class Solution
{
    static int clock;
    static int[] pre;
    static int[] post;
    public static void solve(scc.InputReader in, PrintWriter out)
    {
        System.out.println("Enter number of Vertices");
        int n=in.nextInt();
        System.out.println("Enter number of Edges");
        int m=in.nextInt();
        clock=0;
        pre=new int[n];
        post=new int[n];
        ArrayList<Integer>[] G=(ArrayList<Integer>[])new ArrayList[n];         //Actual Graph
        ArrayList<Integer>[] Gr=(ArrayList<Integer>[])new ArrayList[n];        //Graph with reverse edges  
        /*
        Gr and G have same SCCs, but Source component of Gr are Sink component for G, and as sink has highest post order value we can iterate through the vertices
        having highest postorder and explore the vertices connected to it which will be its SCCs.
        */
        for(int i=0;i<n;i++){
        G[i]=new ArrayList<>();
        Gr[i]=new ArrayList<>();
        }
        System.out.println("Enter Edges:");
        for(int i=0;i<m;i++)
        {
            int a=in.nextInt()-1;
            int b=in.nextInt()-1;
            G[a].add(b);
            Gr[b].add(a);
        }
        SCC(G,Gr);
    }
    //function for SCC implementation
    public static void SCC(ArrayList<Integer>[] G, ArrayList<Integer>[] Gr)
    {
        DFS(Gr);
        System.out.println(Arrays.toString(post));
        HashMap<Integer,Integer> hmap=new HashMap<>();
        int len=post.length;
        for(int i=0;i<len;i++)
        hmap.put(post[i],i);
        Arrays.sort(post);
        boolean[] visit=new boolean[len];
        for(int i=len-1;i>=0;i--)
        {
            // System.out.println(post[i]);
            int v=hmap.get(post[i]);
            if(!visit[v])
            {
                ArrayList<Integer> l=new ArrayList<>();
                ExploreDiff(v, visit, G, l);
                System.out.println("Strongly connected components from "+(v+1)+" are:");
                System.out.println(l);
            }
        }
    }

    //function for DFS
    public static void DFS(ArrayList<Integer>[] adj)
    {
        int len=adj.length;
        boolean[] visit=new boolean[len];
        for(int i=0;i<len;i++)
        {
            if(!visit[i])
            {
                Explore(i,visit,adj);
            }
        }
    }

    //function for exploring edges connected to a vertex "s"
    public static void Explore(int s,boolean[] visit,ArrayList<Integer>[] adj)
    {
        visit[s]=true;
        previsit(s);
        for(int i=0;i<adj[s].size();i++)
        {
            if(!visit[adj[s].get(i)])
            Explore(adj[s].get(i),visit,adj);
        }
        postvisit(s);
    }

    //function to count preorder
    public static void previsit(int s)
    {
        pre[s]=clock;
        clock++;
    }

    //function to count postorder
    public static void postvisit(int s)
    {
        post[s]=clock;
        clock++;
    }

    //Explore function to return the vertices connected to particular vertex "s"
    public static void ExploreDiff(int s,boolean[] visit,ArrayList<Integer>[] adj,ArrayList<Integer> l)
    {
        visit[s]=true;
        for(int i=0;i<adj[s].size();i++)
        {
            if(!visit[adj[s].get(i)]){
                l.add(adj[s].get(i)+1);
            ExploreDiff(adj[s].get(i),visit,adj,l);
            }
        }
    }
}