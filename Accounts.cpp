#include "Accounts.hpp"
#include "Servicefunctions.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin",L"user1",L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin",L"user1",L"user2" };
std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin",L"Admin",L"User" };
unsigned int* userIdArr = new unsigned int[userSize] {0, 1, 2};

size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 10;
size_t minPass = 8;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;

bool IsSetCreated = false;

void ChangeAccounts()
{
	std::wstring choose;
	if (!IsSetCreated)
	{
		CreateSet()
	}

	while (true)
	{
		system("cls");

		std::wcout << L"\n\n\t\t Редактор учет. записей	\n\n";
		std::wcout << L"\n1. Создать новый акк: ";
		std::wcout << L"2. Показать сотрудников: ";
		std::wcout << L"3. Изменить пароль: ";
		std::wcout << L"4. Изменить уровень доступа: ";
		std::wcout << L"5. Редактировать премии штрафы сотруд.: ";
		std::wcout << L"5. Удалить акк.: ";
		std::wcout << L"0. Выход:";
		std::wcout << L"ввод";
		Getline(choose);
		

		if (choose == L"1")
		{


		}
		if (choose == L"2")
		{


		}
		if (choose == L"3")
		{


		}
		if (choose == L"4")
		{


		}
		if (choose == L"5")
		{


		}
		if (choose == L"6")
		{


		}
		if (choose == L"0")
		{
			std::wcout << L"выход из редактора";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}



	}
}

void CreateNewAccount()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;


	while (true)
	{
		system("cls");
		std::wcout << L"ddrtdfj";
		Getline(chooseLogin);
		if (chooseLogin == L"exit" || chooseLogin == L"exit")
		{
			std::wcout << L" отмена созданеия учет";
			Sleep(1500);
			return;
		}
		if (true)
		{
			break;
		}
		else


	}

}


bool CheckLogin(const std::wstring& login)
{
	if (login.size() < minLogin || login.size() > maxLogin)

	{
		std::wcout << L"ошибка длины логмнв допустимо от " << minLogin << L"до"
			<< maxLogin << L"";
		Sleep(1500);
		return false;
	}

	for (size_t i = 0; i < userSize; i++)
	{
		if (login == loginArr[i])
		{
			std::wcout << L"Такой польз сущ";
			Sleep(1500);
			return false;
		}
	}
	int count = 0;
	for (size_t i = 0; i < userSize; i++)
	{
		if (loginSymbols.count(login[i]))
		{
			std::wcout << L"не допустимый символ";
			std::wcout << L"допустимый символ: A-Z, a-z, 0-9";
			Sleep(2000);
			return false;
		}
		else if (login[i] >= L'A' && login[i] <= L'Z') || (login[i] >= L'a' && login[i] <= L'z'))
		{
			count++;
			}
		if (count >= 3)
		{
			return true;
	    }

		else
		{
			std::wcout << L"мало букв симовлов в пароле" << count;
			Sleep(2000);
				return false;
		}
	}
	return true;
}

bool CheckPass(const std::wstring& Pass)
{
	bool CheckPass(const std::wstring & login)
	{
		if (Pass.size() < minPass || Pass.size() > maxPass)

		{
			std::wcout << L"ошибка длины логмнв допустимо от " << minPass << L"до"
				<< maxPass << L"";
			Sleep(1500);
			return false;
		}

	
		int count = 0;
		for (size_t i = 0; i < PassSize; i++)
		{
			if (PassSymbols.count(Pass[i]))
			{
				std::wcout << L"не допустимый символ";
				std::wcout << L"допустимый символ: A-Z, a-z, 0-9, спец симв";
				Sleep(2000);
				return false;
			}
			else if (login[i] >= L'A' && login[i] <= L'Z') || (login[i] >= L'a' && login[i] <= L'z'))
			{
				count++;
			}
			if (count >= 3)
			{
				return true;
			}

			else
			{
				std::wcout << L"мало букв симовлов в пароле" << count;
				Sleep(2000);
				return false;
			}
		}
		return true;
	}
}
void CreateSet()
{
	for (wchar_t i = '0'; i < '9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = 'A'; i < 'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = 'a'; i < 'z'; i++)
	{
		loginSymbols.insert(i);

	}
	for (wchar_t i = '!'; i < '~'; i++)
	{
		passSymbols.insert(i);

	}
	IsSetCreated = true;
	

}