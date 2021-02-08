using System;

namespace Beakjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] ininput = input.Split(" ");

            int a, b, c;
            a = int.Parse(ininput[0]);
            b = int.Parse(ininput[1]);
            c = int.Parse(ininput[2]);

            Console.WriteLine("{0}", (a + b) % c);
            Console.WriteLine("{0}", ((a % c) + (b % c)) % c);
            Console.WriteLine("{0}", (a * b) % c);
            Console.WriteLine("{0}",  ((a%c) * (b%c))%c);
        }
    }
}