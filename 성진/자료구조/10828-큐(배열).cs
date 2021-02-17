using System;
using System.Text;
using System.IO;
using System.Collections;

namespace baekjoon
{
    class Program
    {
        static StringBuilder sb = new StringBuilder();
        static void Main(string[] args)
        {
            int[] queue = new int[10001];
            int repeat = int.Parse(Console.ReadLine());
            int cnt=0;
            int first = 1;
            int last =0;
            for(int i=0;i<repeat;i++)
            {
                string cmd = Console.ReadLine();

                switch(cmd.Substring(0,2))
                {
                    case "pu":
                        last++;
                        queue[last] = int.Parse(cmd.Substring(5));
                        cnt++;

                        break;

                    case "po":
                        if (cnt == 0)
                            st("-1");
                        else
                        {
                            st(queue[first].ToString());
                            first++;
                            cnt--;
                        }
                        break;

                    case "si":
                        st(cnt.ToString());
                        break;

                    case "em":
                        st(cnt == 0 ? "1" : "0");
                        break;

                    case "fr":
                        st(cnt == 0 ? "-1" : queue[first].ToString());
                        break;

                    case "ba":
                        st(cnt == 0 ? "-1" : queue[last].ToString());
                        break;
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
}