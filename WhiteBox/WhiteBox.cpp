#include <iostream>
#include <cmath>
#include <iomanip>

double task(double* arr, int n)
{
	double s = 0;

	int minid = 0;

	// Находим индекс минимального элемента
	for (int i = 1; i < n; i++)
		if (arr[i] < arr[minid])
			minid = i;

	// Вычисляем сумму элементов после минимального
	for (int i = minid + 1; i < n; ++i)
		s += arr[i];

	return s;
}


double checkelem(int n)
{
	double elem;

	std::cout << "Type element: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> elem))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "element is non digit!";
			}
			else
				break;
		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new element: ";
		}
	}
	return elem;
}


int sizechecker(int n)
{
	while (true)
	{
		try
		{
			if (!(std::cin >> n))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "Size is non digit!";
			}
			else
				if (n <= 0 || n > 10)
					throw "Size is out of range!";
				else
					break;

		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new size: ";
		}
	}
	return n;
}

int main()
{
	int n = 0;

	double t;

	std::cout << "Type size of the array: ";

	n = sizechecker(n);

	double* arr = new double[n];

	for (int i = 0; i < n; i++)
		arr[i] = checkelem(n);

	t = task(arr, n);

	std::cout << "Sum = " << t;

	delete[] arr;
	return 0;
}
