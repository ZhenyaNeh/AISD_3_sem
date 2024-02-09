using System;

class Program
{
    static void Main()
    {
        double c = 2.0; // Замените значение c на фактическое
        double d = 1.0; // Замените значение d на фактическое
        int N = 1000;   // Количество разбиений интервала [a, b]
        double a = 0.0; // Начало интервала
        double b = 5.0; // Конец интервала

        double max_x = a; // Переменная для хранения x с максимальным значением f(x)
        double max_f = double.MinValue; // Переменная для хранения максимального значения f(x)

        double step = (b - a) / N; // Размер шага

        for (double x = a; x <= b; x += step)
        {
            double f_x = 4 * x / (d + c * x * x);

            if (f_x > max_f)
            {
                max_f = f_x;
                max_x = x;
            }
        }

        Console.WriteLine("Максимальное значение f(x): " + max_f);
        Console.WriteLine("Значение x, при котором достигается максимум: " + max_x);
    }
}