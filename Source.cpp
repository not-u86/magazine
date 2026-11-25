#include "Authorization.hpp"
#include <io.h> 
#include <fcntl.h> 



int main()
{



	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	

	Start();

	CreateSet();

	std::wstring asd[5](L"12345", L"asdqwef5", L"glfg4")
	

	return 0;
}
