package com.company;

import java.util.Scanner;

class Solution
{
    public static final int MAXSIZE = 50000;
    public static int N;
    public static int[] Mountains = new int[MAXSIZE];
    public static Scanner sc = new Scanner(System.in);

    public static void Init()
    {
        for (int i=0; i<MAXSIZE; i++)
        {
            Mountains[i] = 0;
        }
        N = sc.nextInt();
        for (int i=0; i<N; i++)
        {
            int height = sc.nextInt();
            Mountains[i] = height;
        }
    }

    public static int CalcTowering()
    {
        int answer = 0;
        int start = 0;
        int top = 0;
        boolean isBreak = false;
        for (int i=1; i<N; i++)
        {
            if (!isBreak)
            {
                if (Mountains[i] < Mountains[i-1])
                {
                    if (i ==1)
                    {
                        start = i;
                        continue;
                    }
                    else
                    {
                        isBreak = true;
                        top = i-1;
                        answer += top - start;
                    }
                }
            }
            else
            {
                if (Mountains[i] < Mountains[i-1])
                {
                    answer += top - start;
                }
                else
                {
                    isBreak = false;
                    start = i-1;
                }
            }
        }
        return answer;
    }

    public static void main(String[] args)
    {
        int T;
        T = sc.nextInt();

        for (int testCase = 1; testCase <= T; testCase++)
        {
            Init();
            System.out.println("#" + testCase + " " + CalcTowering());
        }
    }
}