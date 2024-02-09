#include <iostream>

using namespace std;

void tower_Honoi(int count_Cycles, char stick_A, char stick_B, char stick_C);

int main()
{
	int count_Cycles;
	char stick_A = 'A';
	char stick_B = 'B';
	char stick_C = 'C';

	cout << "Write cycle value: ";
	cin >> count_Cycles;

	tower_Honoi(count_Cycles, stick_A, stick_B, stick_C);
}

void tower_Honoi(int count_Cycles, char stick_A, char stick_B, char stick_C)
{
	if (count_Cycles == 1)
	{
		std::cout << "Move disk - 1 from " << stick_A << " to " << stick_C << std::endl;
		return;
	}

	tower_Honoi(count_Cycles - 1, stick_A, stick_C, stick_B);
	std::cout << "Move disk - " << count_Cycles << " from " << stick_A << " to " << stick_C << std::endl;
	tower_Honoi(count_Cycles - 1, stick_B, stick_A, stick_C);
}