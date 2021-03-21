#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <clocale>
#include <malloc.h>
#include <string>
#include <algorithm>

#define M 20
#define N 30
using namespace std;
size_t remove_ch(char* s, char ch)           //функция удаление определенных символов
{
	size_t i, j;

	j = 0;

	for (i = 0; s[i]; ++i)
		if (s[i] != ch)
			s[j++] = s[i];

	s[j] = '\0';

	return j;
}



class Decanat {

public:
	virtual void FindByStudentbook(int np, int n) = 0;

};



class students {

public:

	students& operator =(const students& val) {

		students test;
		for (int i = 0; i < 5; i++)
		{
			test.mas[i] = mas[i];
		}
		return *this;
	}

	students(void) {//конструктор без параметров

		a = 0;

		sum = 0;
		for (int i = 0;i < M;i++) {
			last_name[i] = "\0";
			group[i] = 0;
			avg_ball1[i] = 0;
			avg_ball2[i] = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			mas[i] = i;
		}
	}

	students(int a) {//конструктор с 1 параметром

		this->a = a;

	}

	students(string asd) {

		this->asd = asd;
		std::cout << "\n";
		std::cout << "Выозв конструктора базового класса в конструкторе производного класса:" << asd << endl;
		std::cout << "\n";
	}



	students(std::string student_last_name[N], int grn[N], float avg1[N], float avg2[N], int id[N], int n) :student_book(id,n) {//конструктор со всеми параметрами

		for (int i = 0;i < n;i++) {
			last_name[i] = student_last_name[i];
			group[i] = grn[i];
			avg_ball1[i] = avg1[i];
			avg_ball2[i] = avg2[i];


		}

	}

	students(const students& ref_student);//конструктор копирования 



	//void FindByStudentbook(int np,int n) {
	//
	//
	//	for (int i = 0;i < n;i++) {
	//	
	//		if (group[i] == i)
	//		{
	//			std::cout << last_name[i] << "|" << group[i] << "|" << avg_ball1[i] << "|" << avg_ball2[i] << "|" << student_book.get_id(i) << endl;
	//		}
	//	
	//	}

	//}


	void set_last_name(string str, int i) {

		last_name[i] = str;

	}

	virtual void set(string str[], int i) {//виртуальная функция 

		last_name[i] = str[i];


	}

	virtual string get(int i) {// вирутальный геттер

		return last_name[i];

	}

	void set_nv(string str[], int i) {

		students::set(str, i);

	}

	void set_group(int i, int gn) {

		group[i] = gn;

	}

	int get_group(int i) {

		return group[i];

	}

	string get_last_name(int i) {

		return last_name[i];

	}
	void set_avg_balls(float a, float b) {

		avg_ball1[0] = a;
		avg_ball2[0] = b;

	}

	void output(int n) {//метод для вывода 
		for (int i = 0;i < n;i++) {

			std::cout << last_name[i] << "|" << group[i] << "|" << avg_ball1[i] << "|" << avg_ball2[i] << "|" << student_book.get_id(i) << endl;



		}
	}

	void set_avg_ball1(float a, int i) {

		avg_ball1[i] = a;


	}




	void sort(int n) {
		std::string ln;
		int* g = new int();
		float* a1 = new float();
		float* a2 = new float();
		int* ID = new int();
		int* ID1 = new int();
		for (int i = 0;i < n - 1;i++) {
			for (int j = n - 1;j > i;j--)
				if (group[j - 1] < group[j]) {
					ln = last_name[j - 1];
					last_name[j - 1] = '\0';
					last_name[j - 1] = last_name[j];
					last_name[j] = '\0';
					last_name[j] = ln;
					ln[0] = '\0';


					*g = group[j - 1];
					group[j - 1] = group[j];
					group[j] = *g;

					*a1 = avg_ball1[j - 1];
					avg_ball1[j - 1] = avg_ball1[j];
					avg_ball1[j] = *a1;

					*a2 = avg_ball2[j - 1];
					avg_ball2[j - 1] = avg_ball2[j];
					avg_ball2[j] = *a2;

					*ID = student_book.get_id(j - 1);
					*ID1 = student_book.get_id(j);
					student_book.setId(j - 1, *ID1);
					student_book.setId(j, *ID);


				}


		}

		delete g;
		delete a1;
		delete a2;
		delete ID;
		delete ID1;

	}// сортировка по возрастанию номера группы

	void zadanie(int n) {
		printf("Студенты, у которых оценка за 2 экзамен ниже, чем за первый\n");
		for (int i = 0;i < n;i++) {
			if (avg_ball2[i] < avg_ball1[i]) {

				std::cout << "|" << last_name[i];

			}

		}
	}

	float& sumofballs1(int n) {// возврат по ссылке

		float sum1 = 0;

		for (int i = 0;i < n;i++) {

			sum1 += avg_ball1[i];


		}

		return sum1;

	}




	float* sumofballs2(int n) {//возврат по указателю 

		float sum2 = 0;

		for (int i = 0;i < n;i++) {

			sum2 += avg_ball2[i];


		}

		return &sum2;

	}


	void sumofballs(int n) {

		float sum1 = 0;
		float sum2 = 0;

		for (int i = 0;i < n;i++) {

			sum1 += avg_ball1[i];

			sum2 += avg_ball2[i];
		}

		sum = sum1 + sum2;
		printf("сумма баллов за 2 экзамена:%f\n", sum);

	}





	students operator++(void) {//перегрузка ++

		++a;
		return *this;
	}
	students operator++(int a) {//перегрузка ++

		this->a++;
		return *this;
	}



	float get_a() {//геттер для a

		return a;

	}

	void out_a() {// вывод значения a

		std::cout << "a:" << a << "\n";

	}

	static int get_stipendia() { return stipendia; }

	void out_stipendia(int n) {

		for (int i = 0;i < n;i++) {

			if ((avg_ball1[i] + avg_ball2[i]) / 2 >= 4) {
				std::cout << "Студент:" << last_name[i];
				printf("Стипендия:%d\n", stipendia);

			}
			else
			{
				std::cout << "Студент:" << last_name[i];
				printf("Стипендия:0\n");
			}

		}

	}

	float get_sum()// геттер 
	{

		return sum;

	}

	students& operator=(string str) {//перегрузка оператора прис-я

		ln = str;
		return *this;

	}

	void out_str() {//вывод ln

		std::cout << ln << "\n";
	}
	void operator +(string);//перегрузка оператора +

	void method_A(int a, int b) {//перегрузка метода базового класса в производном

		std::cout << "Base call A" << endl;

	}

	void set_asd(string str) {// для задания 5 

		asd = str;


	}

	string get_asd() {//геттер строки asd 

		return asd;

	}

	int mas[5];
protected:
	string asd;
	int a;
	float avg_balls1;
private:
	std::string last_name[N];// фамилия студента
	std::string ln;
	int group[N];//номер группы студента
	float avg_ball1[N];//средний балл за 1 семестр
	float avg_ball2[N];//средний былл за 2 семестр
	static int stipendia;
	float sum;
	float sum_of_balls1[N];//сумма баллов каждого студента 


	class Student_book
	{
	private:
		int id[M];
	public:
		Student_book() {


		}

		Student_book(int id[N],int n) {
			

			for (int i = 0; i < n;i++) {

				this->id[i] = id[i];

			}


		}




		void setId(int i, int id) {

			this->id[i] = id;
		}



		int get_id(int i)
		{

			return id[i];

		}


	};
	Student_book student_book;
	friend void friendf(students& student);

};

class Spec :public students// класс где указываются спецальности 
{
public:
	students s1;

	using students::method_A;
	Spec() {

	}

	Spec(string str) :students(str) {}//вызов конструктора базового класса в конструкторе производного класса 

	Spec(int n, string spec[N]) {

		for (int i = 0;i < n;i++) {

			this->spec[i] = spec[i];

		}

	}

	void set(string str[], int i) {


		spec[i] = str[i];

	}

	string get(int i) {

		return spec[i];

	}
	void method_A(int a) {//перегрузка метода (задание 3)

		std::cout << "Derived call A" << endl;

	}


	Spec operator = (students& student) {

		asd = student.get_asd();
		return *this;

	}

	string get_spec(int i) {

		return spec[i];

	}

	string get_asd() {

		return asd;

	}

protected:

	std::string spec[N];

};





void students::operator+(string str) {

	ln = ln + str;

}

students::students(const students& ref_student) {

	sum = ref_student.sum;
	students test;
	for (int i = 0; i < 5; i++)
	{
		mas[i] = test.mas[i];
	}

}



int students::stipendia = 2600;

void friendf(students& student)//friend функция
{
	student.sum = 0;
	printf("сумма баллов обнулена\n");

}





int _tmain() {
	std::string Ln[N];
	std::string spec[N];
	int n;
	float* avgb1 = new float[N];
	int* id1 = new int[N];
	setlocale(LC_ALL, "russian");
	printf("Ввдеите кол-во стундентов:");
	do {
		scanf("%d", &n);

		if (n < 0 || n>30)
		{
			printf("Кол-во стундентов должно быть больше 30, но неменьше 1!\n");
		}

	} while (n < 0 || n>30);
	float* avgb2 = (float*)calloc(n, sizeof(float));
	int* groupn = (int*)malloc(n * sizeof(int));
	for (int i = 0;i < n;i++) {
		while (getchar() != '\n');
		printf("Введите фамилию:");
		std::getline(std::cin, Ln[i]);
		printf("Введите номер группы:");
		scanf("%d", &groupn[i]);
		while (getchar() != '\n');
		printf("Введите средный балл за 1 экзамен:");
		scanf("%f", &avgb1[i]);
		while (getchar() != '\n');
		printf("Введите средный балл за 2 экзамен:");
		scanf("%f", &avgb2[i]);
		while (getchar() != '\n');

		try {
			printf("Введите номер зачетки:");
			scanf("%d", &id1[i]);
			if (id1[i] < 0)throw "Номер зачетки не может быть отрицательным\n";
		}
		catch (const char* msg) {
			std::cerr << msg << std::endl;


		}
	}
	students* student = new students(Ln, groupn, avgb1, avgb2, id1, n);
	students st();

	printf("\nДо сортировки:\n");
	student->output(n);
	student->sort(n);
	printf("\nПосле сортировки:\n");
	student->output(n);
	student->zadanie(n);
	printf("\nСумма оценок за 1 экзамен:%f\n", student->sumofballs1(n));
	printf("Сумма оценок за 2 экзамен:%f\n", *student->sumofballs2(n));
	student->sumofballs(n);
	printf("\n");

	std::cout << "Конструктор копирования!\n\n";

	students student1;
	student1.set_avg_balls(4.2, 3.8);
	student1.sumofballs(1);
	students s1 = student1;
	std::cout << "До копирования:";
	for (int i = 0;i < 5;i++) {
		std::cout << student1.mas[i];

	}
	std::cout << "\nКопирование:" << s1.get_sum() << "\n";
	for (int i = 0;i < 5;i++) {
		std::cout << s1.mas[i];

	}
	std::cout << "\nменяем первый элемент массива на 9\n";
	s1.mas[0] = 9;
	for (int i = 0;i < 5;i++) {
		std::cout << s1.mas[i];

	}
	std::cout << "\n";
	friendf(student1);

	std::cout << "\nПрегрузка операторов + и ++\n";

	std::cout << "\nПрегрузка операторов + \n";
	students str1;
	str1 + Ln[1];
	str1 + Ln[0];
	str1.out_str();

	students d, d1(5);
	printf("До перегрузки(++a):");
	d.out_a();
	printf("До перегрузки(a++):");
	d1.out_a();
	++d;
	d1++;
	printf("После перегрузки(++a):");
	d.out_a();
	printf("После перегрузки(a++):");
	d1.out_a();

	std::cout << "\nПрегрузка операторов присвоения \n";
	students c4;
	c4 = Ln[0];

	c4.out_str();

	std::cout << "\nСтатическое поле и метод\n";
	student->out_stipendia(n);

	std::cout << "Одномерный массив объектов\n";

	students mas[3];

	for (int i = 0;i < 3;i++) {

		mas[i].set_avg_balls(i + 2.3, i + 2.5);
		mas[i].sumofballs(1);

	}

	std::cout << "Двумерный  массив объектов\n";
	students mas1[1][2];

	for (int i = 0;i < 1;i++) {

		mas1[i][0].set_last_name(Ln[i], i);
		mas1[i][1].set_group(i, groupn[i]);

	}
	for (int i = 0;i < 1;i++) {

		cout << "Фамилия:" << mas1[i][0].get_last_name(i) << ' ';
		cout << "Номер группы:" << mas1[i][1].get_group(i) << endl;

	}


	while (getchar() != '\n');
	for (int i = 0; i < n; i++)
	{
		student->output(n);
		std::cout << "Специальность:";
		std::getline(std::cin, spec[i]);

	}

	Spec spec1("Конструктор");
	std::cout << "Перегрузка метода базового класса в производном" << endl;
	spec1.method_A(2, 4);
	spec1.method_A(2);

	std::cout << "Перегрузка оператора присвоения объекту производного класса объектов базового класса\n" << std::endl;

	Spec sp1;
	students st1;

	st1.set_asd("Оператор перегружен");
	sp1 = st1;

	std::cout << "\nВывод резудьтата после присвоения объекта базового класса объекту производного класса:" << sp1.get_asd() << std::endl;

	std::cout << "\nВиртаульная функция\n";
	students st2;
	students st3;
	students* pStudents = &st3;
	Spec sp2;
	Spec sp3;

	std::cout << " Вызов виртуальной функции продемонстрировать через ее вызов не виртуальной функцией базового класса" << std::endl;

	for (int i = 0;i < n;i++) {

		st2.set_nv(Ln, i);
		sp2.set(spec, i);


	}

	for (int i = 0; i < n; i++)
	{
		std::cout << "Фамилия:" << st2.get(i) << " " << "Специальность:" << sp2.get(i) << std::endl;
	}

	std::cout << "\n" << std::endl;
	std::cout << "Вызов виртуальной функции через динамические объекты базового и производного классов после присваивания указателя." << std::endl;
	for (int j = 0; j < n; j++)
	{

		pStudents->set(Ln, j);
		std::cout << "Фамилия:" << pStudents->get(j);
		pStudents = &sp3;
		pStudents->set(spec, j);
		std::cout << "Специальность:" << pStudents->get(j) << std::endl;

	}





	delete[] avgb1;
	delete[] id1;
	free(groupn);
	free(avgb2);
	return 0;
}