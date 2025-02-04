#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[]) {
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for(int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for(int j = 0; (size_t)j < arg.length(); j++)
			{
				if (isalpha(argv[i][j]))
                    std::cout << (char)toupper(argv[i][j]);
                else
                    std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
}