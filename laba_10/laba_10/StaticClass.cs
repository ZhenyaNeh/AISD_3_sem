using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_10
{
    internal static class StaticClass
    {
        public static int CheckInt(this ref int checkNum, string message)
        {
            bool check = true;
            while (check)
            {
                Console.Write(message);
                if (Int32.TryParse(Console.ReadLine(), out checkNum))
                {
                    return checkNum;
                }
                Console.Clear();
                for (int i = 0; i < 3; i++)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write($"You write UNCORRECT number! \nTry again");
                    for (int j = 0; j < 4; j++)
                    {
                        Thread.Sleep(200);
                        Console.Write(". ");
                    }
                    Console.ResetColor();
                    Console.Clear();
                }
            }
            return checkNum;
        }

        public static double CheckDouble(this ref double checkNum, string message)
        {
            bool check = true;
            while (check)
            {
                Console.Write(message);
                if (Double.TryParse(Console.ReadLine(), out checkNum))
                {
                    return checkNum;
                }
                Console.Clear();
                for (int i = 0; i < 3; i++)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write($"You write UNCORRECT number! \nTry again");
                    for (int j = 0; j < 4; j++)
                    {
                        Thread.Sleep(200);
                        Console.Write(". ");
                    }
                    Console.ResetColor();
                    Console.Clear();
                }
            }
            return checkNum;
        }
    }
}
