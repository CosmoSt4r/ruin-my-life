#include <iostream>
#include <fstream>

const std::string GREEK_QUESTION_MARK = ";", SPACE = " ";

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
    for (char& c : fileContent)
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
    
    writeToFile(filepath, ruinedContent);
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        ruinFile(argv[i]);
    }

    return 0;
}
