#pragma once
#ifndef _SERVICE_FUNCTIONS_HPP_
#define _SERVICE_FUNCTIONS_HPP_

#include <iostream>
#include <Windows.h>
#include <string>
#include <unordered_set>

void GetLine(std::wstring& str);
bool IsNumber(const std::wstring& str);
bool IsNotSameName(const std::wstring& chooseName, std::wstring* nameArr, size_t commonSize);

template <class ArrType>
void ArrPushBack(ArrType* arr, size_t arrSize)
{
	arrSize++;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[] temp;
}

#endif // !_SERVICE_FUNCTIONS_HPP_
