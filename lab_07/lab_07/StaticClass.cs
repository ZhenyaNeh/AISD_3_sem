using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace lab_07
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

        public static List<int> FindMaxLenght(this List<int> list)
        {

            var newList = new int[list.Count];

            for (int i = 0; i < list.Count; i++)
            {
                newList[i] = 1;
                for (int j = 0; j < i; j++)
                {
                    if (list[i] > list[j] && newList[i] < newList[j] + 1)
                        newList[i] = newList[j] + 1;
                }
            }

            int maxLength = newList[list.Count - 1];

            var result = new List<int>();
            for (int i = list.Count - 1; i >= 0; i--)
            {
                if (newList[i] == maxLength)
                {
                    result.Insert(0, list[i]);
                    maxLength--;
                }
            }
            return result;
        }
    }
}
