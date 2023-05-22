#include <iostream>
#include <fstream>

void create_array(std::ifstream &txt, int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		txt >> a[i];
	}
	std::cout << std::endl;
}

void write_to_file(std::ofstream &txt, int* a, int size)
{
	txt << size << std::endl;
	txt << a[size-1] << " ";
	for (int i = 1; i < size; i++)
	{
		txt << a[i-1] << " ";
	}
	txt << std::endl;
}

void add_to_file(std::ofstream &txt, int* a, int size)
{
	txt << size << std::endl;
	for (int i = 1; i < size; i++)
	{
		txt << a[i] << " ";
	}
	txt << a[0] << std::endl;
}

int main()
{	
	setlocale(LC_ALL, "Russian");
	std::ifstream file_r("in.txt");
	std::ofstream file_w("out.txt", std::ios::out);
	int n1 = 0;
	int n2 = 0;

		if (file_r.is_open())
		{
			file_r >> n1;
			int* arr1 = new int[n1]();
			create_array(file_r, arr1, n1);

			file_r >> n2;
			int* arr2 = new int[n2]();
			create_array(file_r, arr2, n2);

			write_to_file(file_w, arr2, n2);
			add_to_file(file_w, arr1, n1);

			delete[] arr1;
			delete[] arr2;

		}
		else
		{
			std::cout << "Невозможно прочитать файл." << std::endl;
			return 0;
		}

	file_r.close();
	file_w.close();
	return 0;
}


