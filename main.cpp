#include <iostream>
#include <fstream>

const char GREEK_QUESTION_MARK = ';', SPACE = ' ';

void
writeToFile(const std::string& filepath, const std::string& text)
{
    std::fstream file;
	file.open(filepath, std::ios::out);
	if (!file) 
    {
		std::cout << "Unable to create file at " << filepath << std::endl;
        return;
    }
	else 
		std::cout << "File created successfully at " << filepath << std::endl;

	file << text;
    file.close();
}

void
readFromFile(const std::string& filepath, std::string& text)
{
    std::fstream file;
	file.open(filepath, std::ios::in);
    
    if (!file) 
    {
		std::cout << "Unable to open file at " << filepath << std::endl;
        return;
    }
	else 
		std::cout << "File opened successfully at " << filepath << std::endl;

    std::string line;
    while (getline(file, line))
        text += line + '\n';
    file.close();
}

void
ruinFile(const std::string& filepath)
{
    return;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        ruinFile(argv[i]);
    }

    return 0;
}
