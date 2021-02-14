using System;
using System.Collections.Generic;

namespace Beakjoon
{
    class Program
    {
        static void Main()
        {
            List<int> resultlist = new List<int>();
            int[] input = new int[9];
            int result=0;

            //9개의 자연수를 입력받고 그 값들을 모두 더한다!
            for(int i=0; i<9;i++) 
            {
                input[i] = int.Parse(Console.ReadLine()); 
                result += input[i];
            }


            //입력받은 값들의 합에서 2개로 조합할수 있는 모든 경우의 수를 빼본다!
            for (int a=0;a<8;a++)
                for(int b=a+1;b<9;b++)
                    if((result - input[a] - input[b])==100)//이때 100이 나왔다면 그것이 답!
                    {
                        input[a] = 0;//필요없는 두 값은 0으로 바꿔준다
                        input[b] = 0;
                        for (int c = 0; c < 9; c++)
                        { 
                            if (input[c] != 0)//0이 아닌 값들을 리스트에 넣어준다!
                                resultlist.Add(input[c]);
                        }
                        goto exit;
                    }

                exit:;

            int[] resultarr = resultlist.ToArray();//리스트를 배열로 바꿔주고!
            Array.Sort(resultarr);//오름차순으로 정렬 해준다!
            for (int a=0;a<7;a++)//일곱 난쟁이의 키를 출력시킨다!
            {
                Console.WriteLine(resultarr[a]);
            }
        }
    }
}