#include <iostream>
#include <cmath>
using namespace std;

int n, h, i, c, SignChanging;
double x0, x1, step, x, y, min, max, height, value, cell;
bool LowerZero;

int main() {

	//вводим переменные кол-во столбцов, максимальная высота, от куда до куда
	cin >> n >> h >> x0 >> x1;
	//массив, в котором будет храниться искомый рисунок
	bool **arr = new bool* [n];
	for (i = 0; i < n; i++)
		arr[i] = new bool[h];
	//узнаем шаг по шкале х
	step = (x1 - x0) / n;
	//крайний левый х, для которого будем считать значение
	x = x0 + step / 2;
	//!!!ФУНКЦИЯ!!!
	y = x;
	min = y;
	max = y;
	//ищем разброс по шкале у
	for (i = 1; i < n; i++) {
		x += step;
		//!!!ФУНКЦИЯ!!!
		y = x;
		if (y > max) {
			max = y;
		}
		if (y < min) {
			min = y;
		};
	};
	//ищем величину каждой строки по шкале у
	height = (max - min) / h;
	//равно 1 если первое посчтанное значение у меньше 0, т.е. определяем с какого знака ф-ии начинаем
	LowerZero = y < 0;
	for (int i = 0; i < h; i++) {
		//когда значение ф-ии отличается по знаку от LZ это значит, что она сменила знак 
		if (LowerZero != (min + height * i < 0)) {
			//отражаем значение, т.е. значение LZ показывает знак ф-ии
			LowerZero = !LowerZero;
			SignChanging = i;
		};
		for (int j = 0; j < n; j++) {
			x = x0 + step / 2 + step * j;
			//!!!ФУНКЦИЯ!!!
			value = x;
			cell = (min + height * i);
			arr[i][j] = (cell < value) && (value > 0) && (cell > 0) ||
				(cell > value)& (value < 0)& (cell < 0) ? true : false;
		};
	};
	for (int i = h - 1; i >= 0; i--) {
		cout << h - i << " ";
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) cout << "?";
			else cout << " ";
		};
		cout << endl;
		if (SignChanging == i) {
			for (int j = 0; j < n + 2; j++) {
				cout << "'";
			};
			cout << endl;
		};
	};
};
