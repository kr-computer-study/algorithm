using System;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2])%10007;
//2Xn개의 타일을 채우는 경우의 수는 2X(n-1) 의 경우의 수와 2X(n-2) 를 합친것과 같다
        Console.WriteLine(dp[n]);
    }
}
