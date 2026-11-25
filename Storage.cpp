#include "Storage.hpp"
#include "servicefunctions.hpp"
#include <iomanip>

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

bool isStorageCreated = false;
size_t maxStorageSize = 2000;
size_t currentStorageSize = 0;

void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 16;

		size_t idArrStatic[staticSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
		std::wstring nameArrStatic[staticSize]
		{
			L"COLA \"SellDrink\" 250мл",
			L"COLA \"SellDrink\" ZERO 250мл",
			L"COLA \"SellDrink\" CHERRY 250мл",
			L"COLA \"SellDrink\" 500мл",
			L"COLA \"SellDrink\" ZERO 500мл",
			L"COLA \"SellDrink\" CHERRY 500мл",
			L"PEPSI \"PEPSICO\" 330мл",
			L"PEPSI \"PEPSICO\" MAX 500мл",
			L"FANTA \"MarCastelo\" ORANGE 500мл",
			L"SPRITE \"SellDrink\" LEMON 500мл",
			L"MIRINDA \"PEPSICO\" 330мл",
			L"SCHWEPPES \"Tonics\" BITTER LEMON 500мл",
			L"LIPTON \"PEPSICO\" ICE TEA LEMON 500мл",
			L"LIPTON \"PEPSICO\" GREEN TEA 500мл",
			L"RICH \"Juice\" АПЕЛЬСИНОВЫЙ СОК 1л",
			L"RICH \"Juice\" ЯБЛОЧНЫЙ СОК 1л"
		};
		size_t countArrStatic[staticSize] = { 120, 95, 80, 150, 110, 90, 60, 130, 85, 140, 75, 50, 100, 100, 40, 45 };
		double priceArrStatic[staticSize] = { 75.0, 75.0, 85.0, 110.0, 110.0, 120.0, 89.9, 125.0, 115.0, 110.0, 95.0, 135.0, 130.0, 130.0, 199.9, 199.9 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		for (size_t i = 0; i < sizeSt; i++)
		{
			idArr[i] = idArrStatic[i];
			nameArr[i] = nameArrStatic[i];
			countArr[i] = countArrStatic[i];
			priceArr[i] = priceArrStatic[i];
			currentStorageSize += countArrStatic[i];
		}

		isStorageCreated = true;
	}
	else if (mode == 1)
	{
		
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t Склад напитков \n\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара"
			<< L"\t" << L"Кол-во" << L"\t" << L"Цена\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}

		std::wcout << L"\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t Пополнение склада \n\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара"
			<< L"\t" << L"Кол-во\tЦена\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}

		std::wcout << L"\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;

	while (true)
	{
		ShowStorage(1);
		std::wcout << L"\n\nВведите ID товара или \"exit\" для выхода - ";
		GetLine(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n";
			Sleep(1000);
			return;
		}
		else
		{
			bool isNum = true;
			if (chooseId.empty()) isNum = false;
			for (wchar_t c : chooseId) {
				if (!iswalnum(c)) { isNum = false; break; }
			}

			id = std::stoi(chooseId) - 1;
			if (id < 0 || id >= (int)sizeSt)
			{
				std::wcout << L"Ошибка Неверный ID.\n";
				Sleep(1500);
			}
			else
			{
				std::wcout << L"Введите количество товара для пополнения - ";
				GetLine(chooseCount);

				count = std::stoull(chooseCount);

				if (currentStorageSize + count > maxStorageSize)
				{
					std::wcout << L"Некорректное кол-во На складе осталось - "
						<< maxStorageSize - currentStorageSize << L" свободных мест\n";
					Sleep(2000);
				}
				else
				{
					while (true)
					{
						system("cls");
						std::wcout << nameArr[id] << L"\t" << countArr[id] << L"  ---->  "
							<< countArr[id] + count << L"\n\n";
						std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
						GetLine(choose);

						if (choose == L"1")
						{
							std::wcout << L"Расширение склада";

							countArr[id] += count;
							currentStorageSize += count;
							

							currentStorageSize += count;   
							std::wcout << L"Товар успешно пополнен\n\n";
							Sleep(1500);
							break;
						}
						else if (choose == L"2")
						{
							std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
							Sleep(1500);
							break;
						}
						else
						{
							std::wcout << L"Неверный ввод!\n";
							Sleep(1000);
						}
					}
				}
			}
		}
	}
}
void AddNewProduct()
{
	std::wstring name, priceStr, countStr;
	double price;
	size_t count;

	std::wcout << L"\nВведите название нового товара: ";
	GetLine(name);

	std::wcout << L"Введите цену товара: ";
	GetLine(priceStr);

	std::wcout << L"Введите количество товара: ";
	GetLine(countStr);

	price = std::stod(priceStr);
	count = std::stoull(countStr);

	size_t newId = sizeSt + 1;

	ArrPushBack(idArr, sizeSt);
	ArrPushBack(nameArr, sizeSt);
	ArrPushBack(countArr, sizeSt);
	ArrPushBack(priceArr, sizeSt);

	idArr[sizeSt - 1] = newId;
	nameArr[sizeSt - 1] = name;
	countArr[sizeSt - 1] = count;
	priceArr[sizeSt - 1] = price;

	sizeSt++;
	currentStorageSize += count;

	std::wcout << L"\nТовар успешно добавлен!\n";
	Sleep(1500);
}
void RemoveProduct()
{
	std::wstring
}