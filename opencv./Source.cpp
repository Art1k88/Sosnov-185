#include "opencv2/highgui/highgui.hpp" //определяет кросс-платформенные функции взаимодействия с оконной системой
#include "opencv2/imgproc/imgproc.hpp" //определяет основные/традиционные функции цифровой обработки изображений: отрисовка кривых и тому подобное

#include <iostream> //заголовочный файл с классами, функциями и переменными для организации ввода-вывода в языке программирования C++
#include <stdio.h> //стандартный заголовочный файл ввода-вывода заголовочный файл стандартной библиотеки языка Си
#include <stdlib.h> //заголовочный файл стандартной библиотеки языка Си

using namespace cv; //директива позволяет использовать все имена в namespace для использования без имени пространства имен в качестве явного квалификатора
using namespace std; //сообщает компилятору, что мы хотим использовать всё, что находится в пространстве имен std


int main(int argc, char** argv) //целочисленный параметр, содержащий количество аргументов, переданных в программу
{

	//int height = 520; //Ширина
	//int width = 840; //Высота
	//Mat img(height, width, CV_8UC3); //Создание изображения

	//Point textOrg(100, img.rows / 2); //Местоположение
	//int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX; //Фонт
	//double fontScale = 2; //Его масштаб, размер
	//Scalar color(200, 100, 50); //Цвет текста
	//putText(img, "OpenCV step By Step", textOrg, fontFace, fontScale, color);

	//imshow("Hello World", img); //отображает полутоновое изображение I, указывая диапазон отображения как двухэлементный вектор, [low high]

	////	
	setlocale(LC_ALL, "Russian"); //устанавливает локальную информацию
	char filename[80]; // 1.jpg// string //это указатель, ссылающийся на си-строку и в отношении которых компилятор не допустит кода, меняющего значение этой строки посредством этого указателя
	cout << "Введите имя файла, в который хотитие внести изменения, и нажмите Enter" << endl; //Для отображения данных в консоли
	cin.getline(filename, 80); //предназначена для ввода данных из потока, например, для ввода данных из консольного окна
	cout << "Открыт файл";
	cout << filename << endl;
	Mat img = imread(filename, 1);
	namedWindow("Load", WINDOW_AUTOSIZE); 
		imshow("Load", img);
	Mat src_gray; Mat canny_output; Mat _img; 
	cvtColor(img, src_gray, COLOR_RGB2GRAY);
	imwrite("Серое изображение.jpg", src_gray);
	blur(src_gray, src_gray, Size(5, 5));
	imwrite("Размытое изображение.jpg", src_gray);

	double utsu_thresh_val = threshold(src_gray, _img, 0, 255, THRESH_BINARY |
		THRESH_OTSU);
	double high_tresh_val = utsu_thresh_val, lower_thresh_val = utsu_thresh_val *
		0.5;
	cout << utsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_tresh_val, 3);

	
	namedWindow("Серое изображение", WINDOW_AUTOSIZE);
	imshow("Серое изображение", canny_output);
	imwrite("canny_output.jpg", canny_output);


	
	waitKey(0);
	system("pause");

	return 0;

}



