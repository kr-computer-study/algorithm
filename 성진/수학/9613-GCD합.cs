using System;

namespace Beakjoon
{
    class Program
    {

        static void Main(string[] args)
        {
            string num = Console.ReadLine();
            int linenum = int.Parse(num);

            for (int a = 1; a <= linenum; a++)
            {
                long gcd = 0;
                int inputnumber = 0;
                string line = Console.ReadLine();
                string[] linearray = line.Split(" ");
                int[] numarray = new int[100];
                inputnumber = int.Parse(linearray[0]);

                for (int b = 0; b < linearray.Length-1; b++)
                {
                    numarray[b] = int.Parse(linearray[b+1]);
                }

                for (int c = 0; c < inputnumber - 1; c++)
                {
                    for (int d = c + 1; d < inputnumber; d++)
                    {
                        gcd += gcdresult(numarray[c], numarray[d]);
                    }
                }
                Console.WriteLine("{0}", gcd);
            }

            static int gcdresult(int num1, int num2)
            {
                int tmp, result;

                if (num1 < num2)
                {
                    tmp = num1;
                    num1 = num2;
                    num2 = tmp;
                }
                while (num2 != 0)
                {
                    result = num1 % num2;
                    num1 = num2;
                    num2 = result;
                }
                return num1;
            }
        }
    }
}