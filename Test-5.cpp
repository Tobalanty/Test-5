#include <iostream>
#include <math.h>
#include "Constants.h"

double getInitialHeight() {

	while (true) {																					//Запрос на ввод высоты будет повторяться до тех пор, 
		std::cout << "Enter the initial height of the tower in meters: ";							//пока не будет введено корректное значение
		double initial_height;
		std::cin >> initial_height;

		if (std::cin.fail() || initial_height < 0) {												//Проверка на ввод
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, something went wrong. Please, try again." << std::endl;	
		}
		else
			std::cin.ignore(32767, '\n');															//Если всё введено верно, то чистим буфер и возвращаем введдённую высоту
			return initial_height;
	}

}

double calculateHeight(double height, int time) {

	return height - ((Constants::gravity * pow(time, 2)) / 2);										//Высчитываем текующую высоту, на которой находится мяч
}

int main(){


	double height{ getInitialHeight() };
	int sec{ 0 };

	while (true) {																												//Повторяем цикл до тех пор, пока мяч не окажется на земле
		if (calculateHeight(height, sec) <= 0) {

			std::cout << "At " << sec << " seconds, the ball is on the ground." << std::endl;
			break;
		}
		else {
			std::cout << "At " << sec << " seconds, the ball is at the height: " << calculateHeight(height, sec) << "\n\n";
			++sec;
		}

	}

	system("pause");
	return 0;
}