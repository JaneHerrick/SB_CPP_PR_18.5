#include <iostream>
using namespace std;

class Player		// класс содержащий данные об игроке
{
public:
	string namePlayer;		//переменная для записи имени
	int points = 0;			//... для записи очков

	void setData()			//запись данных имени и очков в переменные
	{
		cout << "Name: ";
		cin >> namePlayer;
		cout << "Points: ";
		cin >> points;
		cout << endl;
	}

	void getData()			//вывод данных об игроке
	{
		cout << namePlayer << "\t" << points << endl;
	}
};

int main()
{
	int size = 0;			
	cout << "Enter number of players: ";
	cin >> size;								// задаем размер массива

	cout << endl;

	Player* arrPlayer = new Player[size];       // динамический массив тип-класс  

	for (int i = 0; i < size; ++i)			//заполняем массив данными введеными пользователем
	{
		cout << "Enter player " << i + 1 << endl;
		arrPlayer[i].setData();				//вызываем метод класса 
	}

	

	//сортировка свапом с последнего элемента

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((arrPlayer[j].points) > (arrPlayer[j - 1].points))
			{
				swap(arrPlayer[j], arrPlayer[j - 1]);
			}
		}
	}

	cout << endl;
	cout << "sorted tab:" << endl;

	for (int i = 0; i < size; ++i)			//вывод отсортированных данных
	{
		arrPlayer[i].getData();					
	}

	delete [] arrPlayer;

	return 0;
}
