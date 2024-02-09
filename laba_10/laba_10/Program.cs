namespace laba_10
{
    class Program
    {
        static void Main()
        {
            int numberOfCities = 0;
            int numberOfAnts = 0;
            double alpha = 0;
            double beta = 0;
            double evaporationRate = 0;
            int numberOfIterations = 0;

            numberOfCities.CheckInt("Enter the number of cities: ");
            numberOfAnts.CheckInt("Enter the number of ants: ");
            alpha.CheckDouble("Enter the alpha value: ");
            beta.CheckDouble("Enter the beta value: ");
            evaporationRate.CheckDouble("Enter the evaporation rate: ");
            numberOfIterations.CheckInt("Enter the number of iterations: ");

            AntColony antColony = new AntColony(numberOfCities, numberOfAnts, alpha, beta, evaporationRate);
            antColony.RunAntAlgorithm(numberOfIterations);

            Console.ReadLine();
        }
    }
}