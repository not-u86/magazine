#include "authorization.hpp"
#include "Storage.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			system("cls");
			std::wcout << L"\n\n\t\t\tУспешный вход в SellDrink\n";
			system("pause");
			MainMenu();
		}
		else
		{
			break;
		}
	}
}

bool Login()
{
	std::wstring login, pass;

	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\tWelcome\n\n\t\t\t SellDrink\n\n\n";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		GetLine(login);

		if (login == L"exit" || login == L"Exit")
			return false;

		std::wcout << L"Введите пароль: ";
		GetLine(pass);

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::wcout << L"\nWelcome, " << loginArr[i] << L"!\n";
				std::wcout << L"Уровень доступа: " << statusArr[i] << L"\n";
				currentStatus = statusArr[i];
				return true;
			}
			else
			{
				break;
			}
		}

		std::wcout << L"\nНеверный логин или пароль.\n";
		Sleep(1500);
	}
}


void MainMenu()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"\n\t\t\t\tSellDrink\n\n";
		std::wcout << L"\t\t\t\tГлавное меню\n\n";

		std::wcout << L"\t\t\t\t1. Просмотр товаров\n";
		std::wcout << L"\t\t\t\t2. Пополнение склада\n";
		std::wcout << L"\t\t\t\t3. Добавить новый товар\n";
		std::wcout << L"\t\t\t\t4. Выход\n\n";

		std::wcout << L"\t\t\t\tВыберите действие: ";
		GetLine(choose);

		if (choose == L"1")
		{
			ShowStorage(0);
		}
		else if (choose == L"2")
		{
			AddProduct();
		}
		else if (choose == L"3")
		{
			AddNewProduct();
		}
		else if (choose == L"4")
		{
			return;
		}
		else
		{
			std::wcout << L"\nНеверный выбор!\n";
			Sleep(1000);
		}
	}
}