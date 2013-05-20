#include <iostream>
#include <locale>
#include <sqlite3.h>

using std::cout;
using std::wcout;
using std::endl;
using std::flush;

//Анонимный namespace - способ локализовать названия в текущем модуле. 
namespace {

	//Эта функция вызывается из библиотеки SQLite, когда имеются готовые данные, полученные в результате запроса. 
	int callback(void *num, int argc, char **argv, char **szColName)
	{
		cout << "query num = " << * static_cast <int *> (num) + 1 << endl;
		for(int i = 0; i < argc; i++) cout << szColName[i] << " = " << argv[i] << endl;
		cout << endl << flush;
		return 0;
	}

}

int main(int argc, char **argv) {

	std::locale::global(std::locale(""));
	std::ios::sync_with_stdio(false);

	sqlite3 *db;
	char *szErrMsg = 0;

	//Открываем БД 
//	int rc = sqlite3_open("file.db", &db);
	int rc = sqlite3_open(":memory:", &db); //Открытие БД в оперативной памяти.
//	int rc = sqlite3_open("", &db); //А так открывается временная БД, которая будет удалена при завершении работы программы. 
	if (rc)
	{
		wcout << L"Не могу открыть базу данных, текст ошибки: " << sqlite3_errmsg(db) << endl << flush;
	}
	else
	{
		wcout << L"База данных открыта успешно" << endl << endl << flush;
//		wcout.flush(); //Можно и так, но способ с манипулятором удобнее. 

		//Подготавливаем запросы 
		const char *pSQL[4];
		pSQL[0] = "CREATE TABLE IF NOT EXISTS Employee(ID INTEGER PRIMARY KEY, Firstname varchar(30), Lastname varchar(30), Age smallint)";
		pSQL[1] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Woody', 'Alan', 45)";
		pSQL[2] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Петров', 'Петр', 38)";
		pSQL[3] = "SELECT * FROM Employee";

		//Выполняем запросы
		for (int i = 0; i < 4; i++)
		{
			rc = sqlite3_exec(db, pSQL[i], callback, &i, &szErrMsg);
			if (rc != SQLITE_OK)
			{
				cout << "SQL Error: " << szErrMsg << endl << flush;
				sqlite3_free(szErrMsg);
				break;
			}
		}

		//Закрываем БД 
		if(db) sqlite3_close(db);
	}

	return 0;
}
