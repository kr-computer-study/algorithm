using System;
using System.Collections.Generic;
class Program
{
    static int[,,] arg = new int[21, 21, 21];
    static int Recursive(int a,int b,int c)
    {
        if (a <= 0 || b <= 0 || c <= 0)
            return 1;
        if (a > 20 || b > 20 || c > 20)
            return Recursive(20, 20, 20);
        if (arg[a, b, c] != 0)
            return arg[a, b, c];
        if (a < b && b < c)
            arg[a,b,c] = Recursive(a, b, c - 1) + Recursive(a, b - 1, c - 1) - Recursive(a, b - 1, c);

            arg[a,b,c]= Recursive(a - 1, b, c) + Recursive(a - 1, b - 1, c) + Recursive(a - 1, b, c - 1) - Recursive(a - 1, b - 1, c - 1);
        return arg[a, b, c];
        //재귀 함수의 조건에 맞게 값을 3차원 배열에 저장해준다!!
    }
    static void Main()
    {
        while (true)
        {
           string[] arr = Console.ReadLine().Split();
            int x = int.Parse(arr[0]);
            int y = int.Parse(arr[1]);
            int z = int.Parse(arr[2]);
            if (x == -1 && y == -1 && z == -1)
                break;
            Console.WriteLine("w({0}, {1}, {2}) = {3}", x, y, z, Recursive(x, y, z));
        }
    }
}
