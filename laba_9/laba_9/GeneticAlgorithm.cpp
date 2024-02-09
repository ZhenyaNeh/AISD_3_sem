#include "GeneticAlgorithm.h"

using namespace std;
//---------------------------------------------------------------------------------
//Основные методы

//Скрещивание
children GeneticAlgorithm::crossover(string parent1, string parent2)
{
    int breakingPoint = randNum(1, NUM_OF_CITIES);

    children children;
    string temp1 = parent1.substr(0, breakingPoint);
    string temp2 = parent1.substr(breakingPoint, parent1.length() - breakingPoint);
    string temp3 = parent2.substr(0, breakingPoint);
    string temp4 = parent2.substr(breakingPoint, parent2.length() - breakingPoint);

    children.child1 = temp1;
    children.child2 = temp3;

    for (unsigned int i = 0; i < temp4.size(); i++)
    {
        if (!repeat(children.child1, temp4[i]))
            children.child1 += temp4[i];
    }
    unsigned int childSize = children.child1.size();
    for (unsigned int i = 0; i < parent1.size() - childSize; i++)
    {
        if (i == parent1.size() - childSize - 1)
            children.child1 += '0';
        else
            children.child1 += '$';
    }

    for (unsigned int i = 0; i < children.child1.size(); i++)
    {
        if (children.child1[i] == '$')
            for (unsigned int j = 0; j < parent1.size(); j++)
                if (!repeat(children.child1, parent1[j]))
                {
                    children.child1[i] = parent1[j];
                    break;
                }
    }

    for (unsigned int i = 0; i < temp2.size(); i++)
    {
        if (!repeat(children.child2, temp2[i]))
            children.child2 += temp2[i];
    }
    childSize = children.child2.size();
    for (unsigned int i = 0; i < parent2.size() - childSize; i++)
    {
        if (i == parent2.size() - childSize - 1)
            children.child2 += '0';
        else
            children.child2 += '$';
    }

    for (unsigned int i = 0; i < children.child2.size(); i++)
    {
        if (children.child2[i] == '$')
            for (unsigned int j = 0; j < parent2.size(); j++)
                if (!repeat(children.child2, parent2[j]))
                {
                    children.child2[i] = parent2[j];
                    break;
                }
    }

    return children;
}

//Мутация
string GeneticAlgorithm::mutatedGene(string genome)
{
    while (true)
    {
        int r = randNum(1, NUM_OF_CITIES);
        int r1 = randNum(1, NUM_OF_CITIES);

        if (r1 != r)
        {
            swap(genome[r], genome[r1]);
            break;
        }
    }
    return genome;
}
//Создание геномов популяции
string GeneticAlgorithm::creategenome()
{
    string genome = "0";
    while (true)
    {
        if (genome.size() == NUM_OF_CITIES)
        {
            genome += genome[0];
            break;
        }

        int temp = randNum(1, NUM_OF_CITIES);

        if (!repeat(genome, (char)(temp + 48)))
            genome += (char)(temp + 48);
    }
    return genome;
}


//Подсчитывание маршрута коммивояжера
int GeneticAlgorithm::calculatePath(string genome)
{
    int path = 0;

    for (unsigned int i = 0; i < genome.size() - 1; i++)
    {
        if (map[genome[i] - 48][genome[i + 1] - 48] == INT_MAX)
            return INT_MAX;

        path += map[genome[i] - 48][genome[i + 1] - 48];
    }

    return path;
}


//Подсчитывание минимального маршрута коммивояжера
individual GeneticAlgorithm::findMinPath(vector<individual> population)
{
    vector<individual>::iterator result = min_element(population.begin(), population.end(), lessthan);
    return population[distance(population.begin(), result)];
}

void GeneticAlgorithm::Solve()
{
    //Номер поколения
    int gen = 1;

    vector<individual> population;
    individual temp;

    //Создание популяции
    for (int i = 0; i < POP_SIZE; i++)
    {
        temp.genome = creategenome();//////////////////////////////////////////////////////////////////////

        temp.fitness = calculatePath(temp.genome);
        population.push_back(temp);
    }
    paths.push_back(findMinPath(population));

    cout << "\nНАЧАЛЬНАЯ ПОПУЛЯЦИЯ: " << endl;

    cout << "---------------------------" << endl;
    cout << "ГЕНОМ          ПУТЬ" << endl;

    for (int i = 0; i < POP_SIZE; i++)
        cout << population[i].genome << "    " << population[i].fitness << endl;

    cout << "\n";

    //Эволюции
    while (gen <= EVOL_NUM)
    {
        sort(population.begin(), population.end(), lessthan);
        vector<individual> new_population;

        //Скрещивание
        for (int i = 0; i < POP_SIZE; i += 2)
        {
            if ((i + 1) != POP_SIZE)
            {
                individual p1 = population[i];
                individual p2 = population[i + 1];
                children children = crossover(p1.genome, p2.genome);

                temp.genome = children.child1;
                temp.fitness = calculatePath(temp.genome);
                new_population.push_back(temp);
                temp.genome = children.child2;
                temp.fitness = calculatePath(temp.genome);
                new_population.push_back(temp);
            }
            else
            {
                individual p1 = population[i];
                new_population.push_back(p1);
                break;
            }
        }

        //Мутация
        for (int i = 0; i < POP_SIZE; i++)
        {
            individual p1 = population[i];

            while (true)
            {
                string new_g = mutatedGene(p1.genome);
                individual new_genome;
                new_genome.genome = new_g;
                new_genome.fitness = calculatePath(new_genome.genome);

                //Вероятность того, что мутация произойдёт
                double prob = pow(2.7, -1 * ((new_genome.fitness - population[i].fitness) / randNum(1000, 10000)));
                if (new_genome.fitness <= population[i].fitness || prob > 0.5)
                {
                    new_population[i] = new_genome;
                    break;
                }
                else
                {
                    new_population[i] = p1;
                    break;
                }
            }
        }
        population = new_population;
        cout << "\nПоколение №" << gen << endl;
        cout << "---------------------------" << endl;
        cout << "ГЕНОМ          ПУТЬ" << endl;

        for (int i = 0; i < POP_SIZE; i++)
            cout << population[i].genome << "    " << population[i].fitness << endl;

        cout << "Минимальный путь коммивояжера на " << gen << "-м этапе эволюции: "
            << findMinPath(population).fitness << ", по маршруту: " << findMinPath(population).genome << endl << endl;

        paths.push_back(findMinPath(population));
        gen++;
    }

    //Результат
    vector<individual>::iterator result = min_element(paths.begin(), paths.end(), lessthan);
    cout << "-------------------------------------- РЕЗУЛЬТАТ --------------------------------------" << endl;
    cout << "\nМинимальный путь коммивояжера: " << paths[distance(paths.begin(), result)].fitness << ", по маршруту: "
        << paths[distance(paths.begin(), result)].genome << endl;
}




//--------------------------------------------------------------------------------------------------
// Дополнительные методы

//Генерация рандомного числа в заданном диапазоне
int GeneticAlgorithm::randNum(int start, int end)
{
    int r = end - start;
    int rnum = start + rand() % r;
    return rnum;
}

//Проверка на повторение символов в строке
bool GeneticAlgorithm::repeat(string s, char ch)
{
    for (unsigned int i = 0; i < s.size(); i++)
        if (s[i] == ch)
            return true;

    return false;
}


//Сравнение путей в разных геномах
bool lessthan(struct individual t1, struct individual t2)
{
    return t1.fitness < t2.fitness;
}
