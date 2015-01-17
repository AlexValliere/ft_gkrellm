#include <iostream>
#include <unistd.h>

int main(void)
{
	char username[64] = {0};

	int ret = getlogin_r(username, sizeof(username) - 1);
	
	if (ret == 0)
	{
		std::cout << username << std::endl;
	}

	return 0;
}