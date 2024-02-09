using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_10
{
    public class AntColony
    { 
        private int[,] distances;
        private double[,] pheromones;
        private int numberOfCities;
        private int numberOfAnts;
        private double alpha;
        private double beta;
        private double evaporationRate;

        public AntColony(int numberOfCities, int numberOfAnts, double alpha, double beta, double evaporationRate)
        {
            this.numberOfCities = numberOfCities;
            this.numberOfAnts = numberOfAnts;
            this.alpha = alpha;
            this.beta = beta;
            this.evaporationRate = evaporationRate;

            InitializeDistances();
            InitializePheromones();
        }

        private void InitializeDistances()
        {
            distances = new int[numberOfCities, numberOfCities];

            // Здесь можно реализовать генерацию расстояний между городами.
            // В данном примере используем случайные значения для иллюстрации.

            Random random = new Random();
            for (int i = 0; i < numberOfCities; i++)
            {
                for (int j = 0; j < numberOfCities; j++)
                {
                    if (i == j)
                        distances[i, j] = 0;
                    else
                        distances[i, j] = random.Next(1, 100); // Замените на свой способ генерации расстояний.
                }
            }
        }

        private void InitializePheromones()
        {
            pheromones = new double[numberOfCities, numberOfCities];

            // Инициализация начальных значений феромонов на ребрах графа.
            double initialPheromone = 1.0 / numberOfCities;

            for (int i = 0; i < numberOfCities; i++)
            {
                for (int j = 0; j < numberOfCities; j++)
                {
                    pheromones[i, j] = initialPheromone;
                }
            }
        }

        public void RunAntAlgorithm(int numberOfIterations)
        {
            for (int iteration = 0; iteration < numberOfIterations; iteration++)
            {
                int[][] antPaths = new int[numberOfAnts][];

                for (int ant = 0; ant < numberOfAnts; ant++)
                {
                    antPaths[ant] = AntWalk();
                }

                UpdatePheromones(antPaths);

                Console.WriteLine($"Iteration {iteration + 1}:");
                DisplayBestPath(antPaths);
            }
        }

        private int[] AntWalk()
        {
            int[] path = new int[numberOfCities];
            bool[] visited = new bool[numberOfCities];

            int startCity = 0; // Начинаем с первого города.
            path[0] = startCity;
            visited[startCity] = true;

            for (int i = 1; i < numberOfCities; i++)
            {
                int nextCity = ChooseNextCity(path, visited);
                path[i] = nextCity;
                visited[nextCity] = true;
            }

            return path;
        }

        private int ChooseNextCity(int[] path, bool[] visited)
        {
            int currentCity = path.Last();
            double[] probabilities = CalculateProbabilities(currentCity, visited);

            double randomValue = new Random().NextDouble();
            double cumulativeProbability = 0;

            for (int i = 0; i < numberOfCities; i++)
            {
                if (!visited[i])
                {
                    cumulativeProbability += probabilities[i];

                    if (randomValue <= cumulativeProbability)
                    {
                        return i;
                    }
                }
            }

            // Если случилась ошибка, возвращаем первый непосещенный город.
            return visited.ToList().IndexOf(false);
        }

        private double[] CalculateProbabilities(int currentCity, bool[] visited)
        {
            double[] probabilities = new double[numberOfCities];
            double pheromoneSum = 0;

            for (int i = 0; i < numberOfCities; i++)
            {
                if (!visited[i])
                {
                    pheromoneSum += Math.Pow(pheromones[currentCity, i], alpha) * Math.Pow(1.0 / distances[currentCity, i], beta);
                }
            }

            for (int i = 0; i < numberOfCities; i++)
            {
                if (visited[i])
                {
                    probabilities[i] = 0;
                }
                else
                {
                    probabilities[i] = (Math.Pow(pheromones[currentCity, i], alpha) * Math.Pow(1.0 / distances[currentCity, i], beta)) / pheromoneSum;
                }
            }

            return probabilities;
        }

        private void UpdatePheromones(int[][] antPaths)
        {
            // Испарение феромонов.
            for (int i = 0; i < numberOfCities; i++)
            {
                for (int j = 0; j < numberOfCities; j++)
                {
                    pheromones[i, j] *= (1.0 - evaporationRate);
                }
            }

            // Обновление феромонов на лучших путях.
            for (int ant = 0; ant < numberOfAnts; ant++)
            {
                int[] path = antPaths[ant];
                double pheromoneToAdd = 1.0 / CalculatePathDistance(path);

                for (int i = 0; i < numberOfCities - 1; i++)
                {
                    pheromones[path[i], path[i + 1]] += pheromoneToAdd;
                    pheromones[path[i + 1], path[i]] += pheromoneToAdd;
                }
            }
        }

        private int CalculatePathDistance(int[] path)
        {
            int distance = 0;

            for (int i = 0; i < numberOfCities - 1; i++)
            {
                distance += distances[path[i], path[i + 1]];
            }

            // Добавляем расстояние от последнего города к начальному.
            distance += distances[path.Last(), path.First()];

            return distance;
        }

        private void DisplayBestPath(int[][] antPaths)
        {
            int[] bestPath = antPaths.OrderBy(path => CalculatePathDistance(path)).First();
            int distance = CalculatePathDistance(bestPath);

            Console.WriteLine($"Best Path: {string.Join(" -> ", bestPath)}");
            Console.WriteLine($"Distance: {distance}");
            Console.WriteLine();
        }
    }
}
