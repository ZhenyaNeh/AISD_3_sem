namespace lab_07
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var list = new List<int>();
            int N = 0;
            int el = 0;
            N.CheckInt("Write count of element: ");
            for (int i = 0; i < N; i++)
            {
                el.CheckInt($"Write {i + 1}-st element: ");
                list.Add(el);
            }

            var result = list.FindMaxLenght();
            Console.WriteLine("\nКоличество элементов: " + result.Count);
            Console.WriteLine("Возрастающая подпоследовательность: " + string.Join(", ", result));
        }
    }
}