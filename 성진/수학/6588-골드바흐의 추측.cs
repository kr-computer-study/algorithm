using System;

namespace Beakjoon
{
    class Program
    {
        static int target = 1000000;
        static bool[] primearr = new bool[target + 1];
        static void Main()
        {

            Boolean cnt = false;

            for (int i = 2; i * i <= target; i++)
            {
                if (primearr[i] == true)
                    continue;
                for (int j = i * i; j <= target; j += i)
                {
                    primearr[j] = true;
                }
            }

            while(true)
            {
                string input = Console.ReadLine();
                int number = int.Parse(input);
                if (number == 0)
                    break;
                for(int a=2;a<=target;a++)
                {
                    if(primearr[a]==false && primearr[number-a]==false)
                    {
                        Console.WriteLine("{0} = {1} + {2}", number, a, number - a);
                        cnt = true;
                        break;
                    }
                }
                if (cnt == false)
                    Console.WriteLine("Goldbach's conjecture is wrong.");
            }         
        }
    }
}