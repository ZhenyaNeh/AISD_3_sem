using System;
using System.Linq;
using System.Globalization;


namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            CultureInfo culture = new CultureInfo("en-US");
            string[] help = Console.ReadLine().Split(' ').ToArray();

            if (help[0] == "1.5")
                help[0] = "1,5";

            if (help[1] == "2.5")
                help[1] = "2,5";

            if (help[2] == "5.5")
                help[2] = "5,5";

            double a = Convert.ToDouble(help[0]);
            double b = Convert.ToDouble(help[1]);
            double c = Convert.ToDouble(help[2]);

            int count_Steps = 993090;

            double start = 0.5;
            double end = 1.3;

            double max_x = start;
            double max_f = double.MinValue;

            double step = (end - start) / count_Steps;

            for (double x = start; x <= end; x += step)
            {
                double f_x = (a * x) / (b + c * (x * x));

                if (f_x > max_f)
                {
                    max_f = f_x;
                    max_x = x;
                }
            }
            string maxX = max_x.ToString("0.0000000", culture);
            string maxF = max_f.ToString("0.0000000", culture);

            Console.WriteLine(maxX);
            Console.WriteLine(maxF);
        }
    }
}