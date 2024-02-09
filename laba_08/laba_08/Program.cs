namespace laba_08
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var list = new List<Product>();
            int capacity = 0;
            capacity.CheckInt("Write backpack capacity: ");
            int count = 0;
            count.CheckInt("Write count of element: ");

            for(int i = 0; i < count; i++)
            {
                Console.WriteLine($"Введите информацию о товаре {i + 1}:");
                Console.Write("Название: ");
                string? itemNames = Console.ReadLine();
                int itemWeights = 0;
                itemWeights.CheckInt("Вес: ");
                int itemValues = 0;
                itemValues.CheckInt("Стоимость: ");
                list.Add(new Product(itemNames, itemWeights, itemValues));
            }

            int[,] D = new int[count + 1, capacity +1];

            for(int i = 1; i <= count; i++)
            {
                for(int j = 1; j <= capacity; j++)
                {
                    if (list[i - 1].ItemWeight <= j)
                    {
                        D[i, j] = Math.Max(D[i - 1, j], D[i - 1, j - list[i - 1].ItemWeight] + list[i - 1].Cost);
                    }
                    else
                    {
                        D[i, j] = D[i - 1, j];
                    }
                }
            }

            int maxCapacity = D[count, capacity];
            Console.WriteLine($"\nМаксимальная стоимость: {maxCapacity}");

            Console.WriteLine("\nПредметы в рюкзаке: ");
            int bufCapacity = capacity;
            for (int i = count; i > 0 && maxCapacity > 0; i--)
            {
                if (D[i, bufCapacity] != D[i - 1, bufCapacity])
                {
                    Console.WriteLine(list[i - 1]);
                    maxCapacity -= list[i - 1].Cost;
                    bufCapacity -= list[i - 1].ItemWeight;
                }
            }
        }
    }
}