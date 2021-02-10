using System;
using System.Collections.Generic;

namespace Beakjoon
{
    class Program
    {

        static void Main()
        {
            string input = Console.ReadLine();
            int repeat  = int.Parse(input);
            int[] dp = new int[10];//dp의 0,1,2 값을 정해 두고 규칙을 이용해 10까지의 경우의 수 합을 대입한다!
            dp[0] = 1;
            dp[1] = 2;
            dp[2] = 4;
            for (int i = 3; i < 10; i++)
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            for(int a=0;a<repeat;a++)
            {
                string numberinput = Console.ReadLine();
                int number = int.Parse(numberinput);

                Console.WriteLine(dp[number - 1]);//입력된 값에 대한 모든 경우의 수의 합 출력!
            }
        }
    }
}