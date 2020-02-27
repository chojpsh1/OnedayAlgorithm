import java.util.Scanner;

class Solution
{
    public static final int MAXSIZE = 401;
    public static final int INF = 987654321;
    public static int N;
    public static int M;
    public static int[][] Graph = new int[MAXSIZE][MAXSIZE];
    public static Scanner sc = new Scanner(System.in);

    public static void Init()
    {
        for (int i=0; i<MAXSIZE; i++)
        {
            for (int j=0; j<MAXSIZE; j++)
            {
                Graph[i][j] = INF;
            }
        }
        N = sc.nextInt();
        M = sc.nextInt();
        for (int i=0; i<M; i++)
        {
            int s, e, c;
            s = sc.nextInt();
            e = sc.nextInt();
            c = sc.nextInt();
            Graph[s][e] = c;
        }
    }

    private static void FloydWarshall()
    {
        for (int i=1; i<=N; i++)
        {
            for (int j=1; j<=N; j++)
            {
                for (int k=1; k<=N; k++)
                {
                    if (Graph[j][i] != INF && Graph[i][k] != INF)
                    {
                        Graph[j][k] = Math.min(Graph[j][k], Graph[j][i] + Graph[i][k]);
                    }
                }
            }
        }
    }

    public static int CalcMinCycleLength()
    {
        int min = INF;
        FloydWarshall();
        for (int i=1; i<=N; i++)
        {
            for (int j=1; j<=N; j++)
            {
                if (i == j)
                {
                    min = Math.min(min, Graph[i][j]);
                }
            }
        }
        return min;
    }

    public static void main(String[] args)
    {
        int T;
        T = sc.nextInt();

        for (int testCase = 1; testCase <= T; testCase++)
        {
            Init();
            CalcMinCycleLength();
            System.out.println("#" + testCase + " " + CalcMinCycleLength());
        }
    }
}
