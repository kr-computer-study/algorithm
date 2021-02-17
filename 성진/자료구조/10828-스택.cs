using System;
using System.Text;

namespace baekjoon
{
    class Program
    {
        static StringBuilder strbu = new StringBuilder();
        static int[] st = new int[10001];
        static int stnum = 0;
        static void Main(string[] args)
        {
            int repeat = int.Parse(Console.ReadLine());
            for (int i = 0; i < repeat; i++)
            {
                string cmd = Console.ReadLine();
                switch (cmd.Substring(0, 2))
                {
                    case "pu":
                        stnum++;
                        st[stnum] = int.Parse(cmd.Substring(5));
                        break;
                    case "po":
                        if (stnum == 0)
                        {
                            strbu.Clear();
                            strbu.Append("-1");
                            Console.WriteLine(strbu.ToString());
                        }
                        else
                        {
                            strbu.Clear();
                            strbu.Append(st[stnum]);
                            stnum--;
                            Console.WriteLine(strbu.ToString());
                        }
                        break;
                    case "si":
                        strbu.Clear();
                        strbu.Append(stnum);
                        Console.WriteLine(strbu.ToString());
                        break;
                    case "em":
                        if (stnum == 0)
                        {
                            strbu.Clear();
                            strbu.Append("1");
                            Console.WriteLine(strbu.ToString());
                        }
                        else
                        {
                            strbu.Clear();
                            strbu.Append("0");
                            Console.WriteLine(strbu.ToString());
                        }
                        break;
                    case "to":
                        if (stnum == 0)
                        {
                            strbu.Clear();
                            strbu.Append("-1");
                            Console.WriteLine(strbu.ToString());
                        }
                        else
                        {
                            strbu.Clear();
                            strbu.Append(st[stnum]);
                            Console.WriteLine(strbu.ToString());
                        }
                        break;
                }
            }
        }
    }
}