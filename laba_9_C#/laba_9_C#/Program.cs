namespace laba_9_C_
{
    class GeneticAlgorithm
    {
        static int[,] distances = {
        {0, 25, 40, 31, 27,  2,  8,  7},
        {5,  0, 17,  2, 18,  7, 30, 25},
        {19, 2,  0,  8,  7, 15,  6,  1},
        {9, 50, 24,  0,  6, 40, 31, 27},
        {22, 8,  7, 10,  0, 34,  4, 27},
        {12, 5 , 5, 43,  5,  0, 23, 55},
        {34, 4, 35, 47, 16, 49,  0, 42},
        {19, 34, 95, 62, 4, 52,  4,  0},
    };

        static Random random = new Random();

        static int populationSize = 8; 
        static int offspringCount = 8; 
        static int evolutionCount = 10;

        static void Main()
        {
            /* Console.WriteLine("Введите размер популяции:");
             populationSize = int.Parse(Console.ReadLine());

             Console.WriteLine("Введите количество потомков при скрещивании:");
             offspringCount = int.Parse(Console.ReadLine());

             Console.WriteLine("Введите количество эволюций:");
             evolutionCount = int.Parse(Console.ReadLine());*/

            int[] bestRoute = SolveTSP();

            Console.WriteLine("\nМинимальный путь обхода городов:");
            PrintRoute(bestRoute);

            Console.WriteLine("\nОбщее расстояние: " + CalculateTotalDistance(bestRoute));
        }

        static int[] SolveTSP()
        {
            int[][] population = InitializePopulation();

            for (int evolution = 0; evolution < evolutionCount; evolution++)
            {
                population = EvolvePopulation(population);
                Console.Write($"\nМинимальный путь обхода в {evolution + 1}-st популяции: ");
                PrintRoute(GetBestRoute(population));
                Console.WriteLine("\nОбщее расстояние: " + CalculateTotalDistance(GetBestRoute(population)));
            }

            return GetBestRoute(population);
        }

        static int[][] InitializePopulation()
        {
            int[][] population = new int[populationSize][];

            for (int i = 0; i < populationSize; i++)
            {
                population[i] = GenerateRandomRoute();
            }

            return population;
        }

        static int[] GenerateRandomRoute()
        {
            List<int> route = Enumerable.Range(0, distances.GetLength(0)).ToList();
            route = route.OrderBy(x => random.Next()).ToList();
            return route.ToArray();
        }

        static int[][] EvolvePopulation(int[][] population)
        {
            int[][] newPopulation = new int[populationSize][];

            for (int i = 0; i < populationSize; i++)
            {
                int[] parent1 = SelectParent(population);
                int[] parent2 = SelectParent(population);

                int[] offspring = Crossover(parent1, parent2);

                Mutate(offspring);

                newPopulation[i] = offspring;
            }

            return newPopulation;
        }

        static int[] SelectParent(int[][] population)
        {
            int tournamentSize = 5;
            int[][] tournament = new int[tournamentSize][];

            for (int i = 0; i < tournamentSize; i++)
            {
                tournament[i] = population[random.Next(populationSize)];
            }

            return GetBestRoute(tournament);
        }

        static int[] Crossover(int[] parent1, int[] parent2)
        {
            int startPos = random.Next(parent1.Length);
            int endPos = random.Next(startPos + 1, parent1.Length);

            int[] offspring = new int[parent1.Length];
            Array.Copy(parent1, offspring, startPos);

            List<int> remainingCities = parent2.Except(offspring).ToList();
            for (int i = 0, j = startPos; i < parent2.Length && j < parent2.Length; i++)
            {
                if (!offspring.Contains(parent2[i]))
                {
                    offspring[j] = parent2[i];
                    j++;
                }
            }

            return offspring;
        }

        static void Mutate(int[] route)
        {

            int index1 = random.Next(route.Length);
            int index2 = random.Next(route.Length);

            Swap(route, index1, index2);

        }

        static int[] GetBestRoute(int[][] population)
        {
            return population.OrderBy(route => CalculateTotalDistance(route)).First();
        }

        static void Swap(int[] route, int index1, int index2)
        {
            int temp = route[index1];
            route[index1] = route[index2];
            route[index2] = temp;
        }

        static int CalculateTotalDistance(int[] route)
        {
            int totalDistance = 0;
            for (int i = 0; i < route.Length - 1; i++)
            {
                totalDistance += distances[route[i], route[i + 1]];
            }
            totalDistance += distances[route[route.Length - 1], route[0]]; // Замыкаем цикл

            return totalDistance;
        }

        static void PrintRoute(int[] route)
        {
            foreach (var city in route)
            {
                Console.Write(city + " ");
            }
        }
    }
}