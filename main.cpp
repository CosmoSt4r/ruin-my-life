#include <iostream>
#include <fstream>

const std::string GREEK_QUESTION_MARK = ";", SPACE = " ";

bool
writeToFile(const std::string& filepath, const std::string& text)
{
    std::fstream file;
	file.open(filepath, std::ios::out);
	if (!file) 
    {
		std::cout << "Unable to create file at " << filepath << std::endl;
        return false;
    }

	file << text;
    file.close();

    return true;
}

bool
readFromFile(const std::string& filepath, std::string& text)
{
    std::fstream file;
	file.open(filepath, std::ios::in);
    
    if (!file) 
    {
		std::cout << "Unable to open file at " << filepath << std::endl;
        return false;
    }
	else 
		std::cout << "File opened successfully at " << filepath << std::endl;

    std::string line;
    while (getline(file, line))
        text += line + '\n';
    file.close();

    return true;
}

void
ruinFile(const std::string& filepath)
{
    std::string fileContent;
    if (!readFromFile(filepath, fileContent))
        return;

    std::string ruinedContent = "";
    for (const char& c : fileContent)
    {
        switch (c)
        {
        case ' ':
            ruinedContent += SPACE;
            break;
        case ';':
            ruinedContent += GREEK_QUESTION_MARK;
            break;
        default:
        ruinedContent += c;
            break;
        }
    }
    
    if(writeToFile(filepath, ruinedContent))
        std::cout << "File ruined successfully at " << filepath << std::endl;
    else
        std::cout << "Unable to ruin file at " << filepath << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
        std::cout << "You have to pass filepaths as parameters" << std::endl;

    for (int i = 1; i < argc; ++i)
        ruinFile(argv[i]);

    return EXIT_SUCCESS;
}
