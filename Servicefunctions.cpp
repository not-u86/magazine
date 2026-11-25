#include "servicefunctions.hpp"

void GetLine(std::wstring& str)
{
	std::getline(std::wcin, str, L'\n');
}
