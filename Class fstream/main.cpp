#include <iostream>
#include <fstream>
#include <string>


bool file_insert(std::string path, int pos, std::string str) {
	static std::fstream fs;
	// Этап 1. Получение текста из файла в строку file/
	fs.open(path, std::ios::in);
	if (!fs.is_open())
		return false;
	std::string file, line;
	while (std::getline(fs, line))
		file += line + '\n';
	fs.close();

	// Этап 2. Вставка строки str в строку file  на нужную позицию.
	file.insert(pos, str);
	// Этап 3. Замена содержимого файла содержимым строки file.
	fs.open(path, std::ios::out);
	if (!fs.is_open())
		return false;
	fs << file;
	fs.close();
	return true;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	
	std::string path = "file.txt";
	
	// Ввод и чтение из файла ( класс fstream )

	/*std::fstream fs;
	fs.open(path, std::ios::app | std::ios::in);
	std::cout << fs.tellg() << std::endl; // Показывает где курсор и считает символы.

	if (fs.is_open()) 
	{
		std::cout << "Файл открыт!\n";
		
		// Запись данных в файл.
		
		std::cout << "Введите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		fs << str << '\n';
		
		fs.seekg(0, std::ios::beg);



		// Чтение данных из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (fs.get(sym))
			std::cout << sym;
		std::cout << std::endl;


		fs.close();
	}
	else
		std::cout << "Ошибка открытия файла.\n";
		*/

	// Задание "Вставка в середину файла"
	/*std::cout << "Введите строку -> ";
	std::string str;
	std::getline(std::cin, str);
	std::cout << "Введите позицию для вставки строки -> ";
	std::cin >> n;
	if (file_insert(path, n, str))
		std::cout << " Файл обновлен.\n";
	else
		std::cout << "Ошибка выполнения функции!\n\n";*/
	
	// Задача 1. Парсинг даты.
	std::cout << "Задача 1.\nДата: ";
	std::ifstream datef;
	datef.open("date.txt");

	if (datef.is_open()) {
		std::string dates;
		datef >> dates;
		datef.close();
		
		std::cout << dates << std::endl;
		
		int first_dot = dates.find('.');
		int second_dot = dates.rfind('.');

		int day = std::stoi(dates.substr(0, first_dot));
		int month = std::stoi(dates.substr(first_dot + 1, second_dot - first_dot - 1));
		int year = std::stoi(dates.substr(second_dot+1));

		std::cout << "День: " << day << std::endl;
		std::cout << "Месяц: " << month << std::endl;
		std::cout << "Год: " << year << std::endl;


	

	}


	return 0;





}