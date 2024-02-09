using System;
using System.Globalization;
using System.Collections.Concurrent;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        FindNumber(n);
    }
    
    static void FindNumber(int n)
    {
        int count = 0; 
        for (int i  = 1; i <= 1000; i++)
        {
            for (int j = i; j <= 1000; j++)
            {
                double c = Math.Pow(Math.Pow(i, n) + Math.Pow(j, n), 1.0 / n);
                if (c == (int)c && c >= i && c >= j)
                {
                    Console.WriteLine($"{i}^{n} + {j}^{n} = {c}^{n}");
                    count++;
                }
            }
        }
        if (count == 0) 
            Console.WriteLine("-1");
    }
}