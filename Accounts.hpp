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

extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;

extern bool IsSetCreated;

void ChangeAccounts();
void CreateNewAccount();

void CreateSet();

bool CheckLogin(const std::wstring& Login);

bool CheckPass(const std::wstring& Pass);


#endif // !_ACCOUNTS_HPP_