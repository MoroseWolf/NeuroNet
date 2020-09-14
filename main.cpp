#include "NeuroNet.h"

using namespace std;

int main()
{
	setlocale(0, "");
	Perceptron PR = Perceptron();
	PR.learn_full();


	cout << "Обученность персептрона на цифры 0-9\n\n";

	for (int i = 0; i < 10; i++) {
		PR.perceptr[i].setNumber(i);
		cout << "Распознание " << i <<": " << PR.perceptr[i].summ_active() << endl;
		PR.perceptr[i].show_weight();
		cout << "\n";
	}
	
	system("pause");
	return 0;
}
