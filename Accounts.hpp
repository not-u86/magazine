#pragma once
#ifndef _ACCOUNTS_HPP_
#define _ACCOUNTS_HPP_

#include "servicefunctions.hpp"

extern std::wstring* loginArr;
extern std::wstring* passArr;
extern std::wstring* statusArr;
extern unsigned int* userIdArr;

extern size_t userSize;
extern size_t currentId;
extern std::wstring currentStatus;

#endif // !_ACCOUNTS_HPP_