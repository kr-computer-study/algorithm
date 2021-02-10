using System;
using System.Collections.Generic;

namespace Beakjoon
{
    class Program
    {
        static void Main()
        {
            string input = Console.ReadLine();
            string[] inputarr = input.Split(" ");
            int earth = int.Parse(inputarr[0]), sun = int.Parse(inputarr[1]), moon = int.Parse(inputarr[2]);//각 숫자를 입력받고 저장한다
            int earthcnt = 0, suncnt = 0,mooncnt = 0,resultcnt=0;

            while(true)//카운트를 하나씩 늘려나가며 입력된 값과 같아질 때까지 계속 반복한다!
            {
                earthcnt++;
                suncnt++;
                mooncnt++;
                resultcnt++;
                if (earthcnt == 16)//15가 넘을시 1
                    earthcnt = 1;
                if (suncnt == 29)//28가 넘을시 1
                    suncnt = 1;
                if (mooncnt == 20)//19가 넘을시 1
                    mooncnt = 1;

                if (earthcnt == earth && suncnt == sun && mooncnt == moon)
                {
                    Console.WriteLine(resultcnt);
                    break;
                }
            }


        }
    }
}