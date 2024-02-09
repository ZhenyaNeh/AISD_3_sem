using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class Program
    {
        static void Main(string[] args)
        {


            int g = 0;
            int s = 0;
            int c = 0;

            int[] help = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            g = help[0];
            s = help[1];
            c = help[2];

            int cuper = c / (g * s + s + 1);
            int silver = cuper * s;
            int gold = silver * g;

            Console.WriteLine(gold);
            Console.WriteLine(silver);
            Console.WriteLine(cuper);
        }
    }
}
