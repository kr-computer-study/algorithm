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
                Stack<char> st = new Stack<char>();//문자를 저장할 스택 하나를 만들어준다! 형식 무관!
                string vps = Console.ReadLine();
                foreach (char ch in vps)//문자열 길이반큼 반복!
                {
                    if (ch == '(')
                        st.Push(ch);//'('가 있으면 스택에 저장! ')'가 있으면 POP!
                    else
                    {
                        if (st.Count == 0)// 카운트가 0일때 ')'을 하는것은 백프로 NO를 출력! 스택에 아무거나 넣어준다!
                        {
                            st.Push('e');
                            break;
                        }
                        st.Pop();
                    }
                }
                if (st.Count == 0)
                    Console.WriteLine("YES");
                else
                    Console.WriteLine("NO");
            }
        }
    }
}