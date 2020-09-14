#pragma once
#include <Windows.h>
#include <math.h>
#include <iostream>

#define bias 36 //����� ���������

class my_Neural {
	bool number[6][6]; // ������� ��������
	int weight[6][6]; //���� ������� ����������
	
public:
	my_Neural();
	void setNumber(int number);
	void setNumber(const bool number[6][6]);
	void weightUp();
	void weightDown();
	bool summ_active();
	void learning(int number);
	void show_weight();
};

class Perceptron {
public:
	my_Neural perceptr[10];
	Perceptron();
	void learn_full();
};