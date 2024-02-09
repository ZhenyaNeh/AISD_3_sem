//#include <iostream>
//
//using namespace std;
//
//void tower_Honoi(int count_Cycles, char stick_A, char stick_B, char stick_C);
//
//void show_Tower(int** towers, int count_Cycles, int count_Stick)
//{
//
//	for (int i = 0; i < count_Cycles; i++)
//	{
//		for (int j = 0; j < count_Cycles; j++)
//		{
//			cout << towers[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//
//
//int main()
//{
//	int count_Cycles, count_Stick;
//	char stick_A = 'A';
//	char stick_B = 'B';
//	char stick_C = 'C';
//
//	cout << "Write cycle value: ";
//	cin >> count_Cycles;
//	int** towers = new int* [count_Cycles];
//	for (int i = 0; i < count_Cycles; i++)
//	{
//		towers[i] = new int[3];
//	}
//
//	for (int i = 0; i < count_Cycles; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			towers[i][j] = 0;
//		}
//	}
//
//	for (int i = 0; i < count_Cycles; i++)
//	{
//		towers[i][0] = i + 1;
//	}
//
//	show_Tower(towers, count_Cycles, 3);
//	/*cout << "Write stick value: ";
//	cin >> count_Stick;*/
//
//	tower_Honoi(count_Cycles, stick_A, stick_B, stick_C);
//}
//
//
//
//
//
//
//
//
//
//void tower_Honoi(int count_Cycles, char stick_A, char stick_B, char stick_C)
//{
//	if (count_Cycles == 1)
//	{
//		std::cout << "Move disk - 1 from " << stick_A << " to " << stick_C << std::endl;
//		return;
//	}
//
//	tower_Honoi(count_Cycles - 1, stick_A, stick_C, stick_B);
//	std::cout << "Move disk - " << count_Cycles << " from " << stick_A << " to " << stick_C << std::endl;
//	tower_Honoi(count_Cycles - 1, stick_B, stick_A, stick_C);
//}