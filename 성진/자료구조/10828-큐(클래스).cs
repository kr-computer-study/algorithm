using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static StringBuilder sb = new StringBuilder();
        static void Main(string[] args)
        {

            int repeat = Convert.ToInt32(Console.ReadLine());
            Queue<int> qu = new Queue<int>();

            for (int i = 0; i < repeat; i++)
            {
                string cmd = Console.ReadLine();

                switch (cmd)
                {
                    case "pop": st((qu.Count > 0) ? qu.Dequeue().ToString() : "-1"); break;
                    case "size":st(qu.Count.ToString()); break;
                    case "empty": st((qu.Count > 0) ? "0" : "1"); break;
                    case "front": st((qu.Count > 0) ? qu.First().ToString() : "-1"); break;
                    case "back": st((qu.Count > 0) ? qu.Last().ToString() : "-1"); break;
                    default:
                        qu.Enqueue(int.Parse(cmd.Substring(5)));
                        break;
                }
            }
        }
       static void st(string strcmd)
        {
            sb.Clear();
            sb.Append(strcmd);
            Console.WriteLine(sb);
        }
    }
}