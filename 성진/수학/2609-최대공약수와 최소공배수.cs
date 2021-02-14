using System;

namespace Beakjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] inputarray = input.Split(" ");

            int num1, num2,output1,output2,tmp,result;
            num1 = int.Parse(inputarray[0]);
            output1= int.Parse(inputarray[0]);
            num2 = int.Parse(inputarray[1]);
            output2 = int.Parse(inputarray[1]);


            if (num1<num2)
            {
                tmp = num1;
                num1 = num2;
                num2 = tmp;
            }
            while(num2!=0)
            {
                result = num1 % num2;
                num1 = num2;
                num2 = result;
            }
            Console.WriteLine(num1);
            Console.WriteLine(output1 * output2 / num1);
        }
    }
}