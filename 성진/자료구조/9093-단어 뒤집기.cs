using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int repeat = int.Parse(Console.ReadLine());

            for (int a = 0; a < repeat; a++)
            {
                StringBuilder sb = new StringBuilder();
                Stack<string> st = new Stack<string>();
                string[] str = Console.ReadLine().Split(" ");
                for (int i = 0; i < str.Length; i++)
                {
                    for (int j = 0; j < str[i].Length; j++)
                        st.Push(str[i].Substring(j, 1));
                    for (int j = 0; j < str[i].Length; j++)
                        sb.Append(st.Pop());

                    sb.Append(" ");
                }
                Console.WriteLine(sb);
            }
        }
    }
}