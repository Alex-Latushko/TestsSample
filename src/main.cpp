#include <iostream>
#include <vector>
#include <cassert>

int sum_for_tests(int x, int y) {
	return x + y;
}

int wrong_sum_for_tests(int x, int y) {
	return x + y + 1;
}

void test_functions() {
	struct one_data{
		int lv;  // left value
		int rv;  // right value
		int res; // result
	};

	// данные для теста
	std::vector<one_data> test_data = { {5, 5, 10},
										{0, 0, 0},
										{-1, 1, 0},
										{5, 2, 7}
									  };

	bool fucntion_works_properly = true;
	std::cout << "Start testing sum_for_tests..." << std::endl;
	for (one_data data : test_data) {
		int result = sum_for_tests(data.lv, data.rv);
		if (result == data.res) {
			std::cout << "+++: " << data.lv << " + " << data.rv << " equals " << result << std::endl;
		} else {
			fucntion_works_properly = false;
			std::cout << "---: " << data.lv << " + " << data.rv << " doesn't equal " << result << std::endl;
		}
	}
	std::cout << "Finished testing sum_for_tests." << std::endl;
	if (fucntion_works_properly) {
		std::cout << "The function works properly" << std::endl;
	} else {
		std::cout << "The function doesn't work properly" << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl << std::endl;

	// по-хорошему это должно быть отдельной функцией, но там нужны указатели на функцию, не будем усложнять.
	std::cout << "Start testing wrong_sum_for_tests..." << std::endl;
	for (one_data data : test_data) {
		int result = wrong_sum_for_tests(data.lv, data.rv);
		if (result == data.res) {
			std::cout << "+++: " << data.lv << " + " << data.rv << " equals " << result << std::endl;
		}
		else {
			fucntion_works_properly = false;
			std::cout << "---: " << data.lv << " + " << data.rv << " doesn't equal " << result << std::endl;
		}
	}
	std::cout << "Finished testing wrong_sum_for_tests." << std::endl;
	if (fucntion_works_properly) {
		std::cout << "The function works properly" << std::endl;
	}
	else {
		std::cout << "The function doesn't work properly" << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl << std::endl;
}

int main() {
	test_functions(); // запускаем тесты в начале работы программы

	//По хорошему, тесты должны вернуть bool, всё ли хорошо прошло. ... Если всё прошло нормально, работаем дальше. 

	std::cout << "Hello, world!" << std::endl;

	// ещё есть вот такая штука. Расскоменть строку ниже. Работает только в debug сборке, а не в release.
	// assert(false && "Test false");
	return 0;
}