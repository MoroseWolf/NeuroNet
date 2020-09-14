#include "NeuroNet.h"

#define numTraining 10000
using namespace std;

//Данные для обучения
struct Input_signals {
	const bool num0[6][6] = {
	{ 1,1,1,1,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,1,1,1,1 } };

	const bool num1[6][6] = {
	{ 0,0,0,0,1,1 },
	{ 0,0,0,1,1,1 },
	{ 0,0,1,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,1,1,1,1 } };

	const bool num2[6][6] = {
	{ 1,1,1,1,1,1 },
	{ 0,0,0,1,1,1 },
	{ 0,0,1,1,1,0 },
	{ 0,1,1,1,0,0 },
	{ 1,1,1,0,0,0 },
	{ 1,1,1,1,1,1 } };

	const bool num3[6][6] = {
	{ 1,1,1,1,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,1,1,1,1,1 },
	{ 0,1,1,1,1,1 },
	{ 0,0,0,0,1,1 },
	{ 1,1,1,1,1,1 } };

	const bool num4[6][6] = {
	{ 1,1,0,0,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,1,1,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 } };

	const bool num5[6][6] = {
	{ 1,1,1,1,1,1, },
	{ 1,1,0,0,0,0 },
	{ 1,1,1,1,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 1,1,1,1,1,1 } };

	const bool num6[6][6] = {
	{ 1,1,1,1,1,1, },
	{ 1,1,0,0,0,0 },
	{ 1,1,1,1,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,1,1,1,1 } };

	const bool num7[6][6] = {
	{ 0,1,1,1,1,1 },
	{ 0,1,1,1,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 } };

	const bool num8[6][6] = {
	{ 1,1,1,1,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,1,1,1,1 },
	{ 1,1,1,1,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,1,1,1,1 } };

	const bool num9[6][6] = {
	{ 1,1,1,1,1,1 },
	{ 1,1,0,0,1,1 },
	{ 1,1,1,1,1,1 },
	{ 0,0,0,0,1,1 },
	{ 0,0,0,0,1,1 },
	{ 1,1,1,1,1,1 } };
}num;

//Инициализация нейронов (заполнение начальных весов)
my_Neural::my_Neural() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			weight[i][j] = 0;
		}
	}
}

//Вывод весов на экран
void my_Neural::show_weight() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << weight[i][j] << " ";
		}
		cout << endl;
	}
}

//Функция суммирования и активации
bool my_Neural::summ_active() {
	int net = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			net += (number[i][j] * weight[i][j]);
		}
	}
	return (net >= bias);
}

//Установка входного параметра 
void my_Neural::setNumber(const bool number[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			this->number[i][j] = number[i][j];
		}
	}
}

//Установка входного параметра
void my_Neural::setNumber(int number) {
	switch (number) {
	case 0:setNumber(num.num0); break;
	case 1:setNumber(num.num1); break;
	case 2:setNumber(num.num2); break;
	case 3:setNumber(num.num3); break;
	case 4:setNumber(num.num4); break;
	case 5:setNumber(num.num5); break;
	case 6:setNumber(num.num6); break;
	case 7:setNumber(num.num7); break;
	case 8:setNumber(num.num8); break;
	case 9:setNumber(num.num9);
	}
}

//Увеличение весов
void my_Neural::weightUp() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (number[i][j]) {
				weight[i][j] += 1;
			}
		}
	}
}

//Уменьшение весов
void my_Neural::weightDown() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (number[i][j]) {
				weight[i][j] -= 1;
			}
		}
	}
}

// Обучение нейрона
void my_Neural::learning(int number) {

	for (int i = 0; i <numTraining; i++) {
		int random_number = rand() % 10;
		this->setNumber(random_number);
		if (random_number == number) {
			if (!(this->summ_active())) this->weightUp();
		}
		else {
			if (this->summ_active()) this->weightDown();
		}

	}
}

///////////////////////////////////////////
//////////////////////////////////////////

//Инициализация  персептрона 
Perceptron::Perceptron() {
	for (int i = 0; i < 10; i++) {
		perceptr[i] = my_Neural();
		perceptr[i].setNumber(i);
	}
};

//Обучение нейронной сети на распознавание всех цифр
void Perceptron::learn_full()
{
	for (int i = 0; i < 10; i++)
		perceptr[i].learning(i);

};