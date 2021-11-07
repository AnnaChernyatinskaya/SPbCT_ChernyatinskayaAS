#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

string DOW(int);
void show_menu();

class Time_Table
{
private:
	struct Pacient
	{
		int day;
		string name;
		int time;
		int insurance;
		Pacient* next;
		Pacient* prev;
	};
	Pacient* Head;
	Pacient* Tail;

public:
	Time_Table() { Head = Tail = NULL; };
	bool Head_chker() { if (Head == NULL) return 1; else return 0; }
	~Time_Table();
	void show_day();
	void show_week();
	void push(int, string, int, int);
	void pop(int, string, int, int);
	bool Repeat_Checker(int);
	void File_Save(ofstream&);
	void File_Read(ifstream&, Time_Table&);

};

bool Time_Table::Repeat_Checker(int i)
{
	Pacient* temp = Head;
	while (temp != NULL)
	{
		if (temp->time == i) return 0;
		temp = temp->next;
	}
	return 1;
}

Time_Table::~Time_Table()
{
	while (Head)
	{
		Tail = Head->next;
		delete Head;
		Head = Tail;
	}
}

void Time_Table::push(int D, string N, int T, int I)
{
	Pacient* person = new Pacient;
	bool err = ((D > 5 || D < 1) || (T > 17 || T < 8));
	if (err)
		cout << "Извините, но мы работаем с понедельника по пятницу, с 8:00 часов утра до 17:00 часов вечера." << endl;
	else
	{
		person->day = D;
		person->name = N;
		person->time = T;
		person->insurance = I;
		if (Head == NULL)
		{
			person->prev = NULL;
			person->next = NULL;
			Head = Tail = person;
			cout << "Запись добавлена!" << endl;
		}
		else
		{
			if (Repeat_Checker(person->time))
			{
				Pacient* temp = Head;
				bool flag = true;
				bool checker = person->time == temp->time;

				if (person->time < temp->time)
				{
					Head->prev = person;
					person->next = Head;
					person->prev = NULL;
					Head = person;
				}
				else
				{
					while (flag)
					{
						if (temp->next == NULL)
						{
							person->prev = temp;
							person->next = NULL;
							temp->next = person;
							Tail = person;
							flag = 0;
						}
						else
						{
							temp = temp->next;

							if (person->time < temp->time)
							{
								person->next = temp;
								person->prev = temp->prev;
								temp->prev->next = person;
								temp->prev = person;
								flag = 0;
							}
						}
					}
				}
				cout << "Запись добавлена!" << endl;
			}
			else cout << "Запись невозможна, так как данное время занято. Пожалуйста, посмотрите другое, подходящее для вас время." << endl;
		}
	}
}

void Time_Table::pop(int D, string N, int T, int I)
{
	if (Head == NULL) cout << "Удаление невозможно. Список пуст." << endl;
	else
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = NULL;
		}
		else
		{
			bool flag = true;
			Pacient* temp = Head;
			while (flag)
			{
				if (D == temp->day && N == temp->name && temp->time == T && I == temp->insurance)
				{
					if (temp == Head)
					{
						temp->next->prev = NULL;
						Head = temp->next;
						delete temp;
						flag = false;
					}
					else
					{
						if (temp == Tail)
						{
							temp->prev->next = NULL;
							Tail = temp->prev;
							delete temp;
							flag = false;
						}
						else
						{
							temp->prev->next = temp->next;
							temp->next->prev = temp->prev;
							delete temp;
							flag = false;
						}
					}
				}
				else temp = temp->next;
			}
		}
		cout << "Удаление прошло успешно!" << endl;
	}
}

void File_Read(ifstream& f, Time_Table* W)
{
	string name, blank;
	int day, time_pass, insurance;
	if (!f)
	{
		cout << "Ошибка. Проверьте название файла." << endl;
	}
	else
	{

		while (!f.eof())
		{
			f >> name;
			f >> day;
			f >> time_pass;
			f >> insurance;
			W[day - 1].push(day, name, time_pass, insurance);
		}
		cout << "Файл был успешно считан!";
		cout << blank;
	}
}

void Time_Table::show_day()
{
	Pacient* temp = Head;
	while (temp != NULL)
	{
		cout << endl << "Назначенный день: " << DOW(temp->day) << endl;
		cout << "ФИО пациента: " << temp->name << endl;
		cout << "Номер мед. полиса: " << temp->day << endl;
		cout << "Время приема: " << temp->time << ":00" << endl << endl;
		temp = temp->next;
	}
}

void Time_Table::File_Save(ofstream& f)
{
	Pacient* temp = Head;
	while (temp != NULL)
	{
		f << endl << "Назначенный день: " << DOW(temp->day) << endl;
		f << "ФИО пациента: " << temp->name << endl;
		f << "Номер мед. полиса:" << temp->day << endl;
		f << "Время приема: " << temp->time << ":00" << endl << endl;
		temp = temp->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Time_Table RJD1, RJD2, RJD3, RJD4, RJD5;
	Time_Table week[5] = { RJD1, RJD2, RJD3, RJD4, RJD5 };

	string name;
	int time_pass, insurance;
	int k, day;

	show_menu();
	cout << endl << "Выберите действие: " << endl;
	k = _getch();
	cout << endl;

	while (k != 'Q')
	{

		switch (k)
		{
		case '1':
		{
			ifstream r("input.txt");
			File_Read(r, week);
			r.close();
		}; break;

		case '2':
		{

			for (int i = 0; i < 5; i++)
			{
				cout << "-----------------------" << DOW(i + 1) << "------------------------" << endl;
				if (week[i].Head_chker())
					cout << "Записей на сегодня нет!" << endl;
				else
					week[i].show_day();
				cout << "------------------------------------------------------" << endl;
			}

			cout << endl << "--------------------------ВЫХОДНОЙ---------------------------" << endl;
			cout << "--------------------------ВЫХОДНОЙ---------------------------" << endl;


		}; break;


		case '3':
		{
			cout << endl << "Выберите день: ";
			cin >> day;
			cout << "-------------" << DOW(day) << "---------" << endl;

			if (week[day - 1].Head_chker())
				cout << "Записей на сегодня нет" << endl;
			else
				week[day - 1].show_day();

		}; break;


		case '4':
		{
			cout << "Введите ФИО: ";
			cin >> name;
			cout << "Введите номер мед. полиса: ";
			cin >> insurance;
			cout << "Выберите день: ";
			cin >> day;
			cout << "Выберите время: ";
			cin >> time_pass;

			week[day - 1].push(day, name, time_pass, insurance);
		}; break;

		case '5':
		{

			cout << "Удаление записи:" << endl;
			cout << "Введите ФИО пациента: ";
			cin >> name;
			cout << "Введите номер мед. полиса: ";
			cin >> insurance;
			cout << "Введите назначенный день приема: ";
			cin >> day;
			cout << "Введите время приема: ";
			cin >> time_pass;
			week[day - 1].pop(day, name, time_pass, insurance);
		}; break;

		case '6':
		{
			ofstream f("output.txt");
			for (int i = 0; i < 5; i++)
			{
				f << "-----------------------" << DOW(i + 1) << "------------------------" << endl;
				if (week[i].Head_chker())
					f << "Записей на сегодня нет!" << endl;
				else
					week[i].File_Save(f);
				f << "------------------------------------------------------" << endl;
			}

			f << endl << "--------------------------ВЫХОДНОЙ---------------------------" << endl;
			f << "--------------------------ВЫХОДНОЙ---------------------------" << endl;
			f.close();
			cout << "Расписание успешно сохранено в файл!\n Чтобы загрузить сохраненный файл переименуйте его в input.txt!" << endl;
		}; break;

		default:
		{
			cout << "Простите, данной цифры в меню нет. Попробуйте ещё раз.";
		}; break;
		};
		cout << "\n\nДля перехода в главное меню нажмите на любую кнопку.";
		_getch();
		system("CLS");
		show_menu();
		cout << endl << "Выберите действие: " << endl;
		k = _getch();
		cout << endl;
	}
	return 0;
}

string DOW(int D)
{
	switch (D)
	{
	case 1: return "Понедельник"; break;
	case 2: return "Вторник"; break;
	case 3: return "Среда"; break;
	case 4: return "Четверг"; break;
	case 5: return "Пятница"; break;
	default: return "Не рабочий день.";
	}
}

void show_menu()
{
	cout << "Выберите действие (введите цифру): " << endl;
	cout << "1. Формирование расписания с файла" << endl;
	cout << "2. Показать расписание на неделю" << endl;
	cout << "3. Показать расписание конкретного дня" << endl;
	cout << "4. Добавить запись" << endl;
	cout << "5. Удалить запись" << endl;
	cout << "6. Сохранить расписание в файл" << endl;
}
