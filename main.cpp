#include <iostream>
#include <fstream>

bool
writeToFile(const std::string& filepath, const std::string& text)
{
    // Function to write text into file

    // Creates new file at given filepath (replaces if already exists)
    // Writes given text into file
    // Returns true if succeeded else false

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
    // Function to read text from file

    // Opens file at given filepath
    // Reads and saves all text from file to given text variable
    // Returns true if succeeded else false

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
ruinCode(std::string& text)
{
    // Function to ruin code

    // Replaces all semicolons with greek question marks
    // and vanilla spaces with space characters 
    // Writes ruined code into given text variable
    // !--doesn't return any value--!

    const std::string GREEK_QUESTION_MARK = ";", SPACE = " ";
    std::string ruinedText = "";

    for (const char& c : text)
    {
        switch (c)
        {
        case ' ':
            ruinedText += SPACE;
            break;
        case ';':
            ruinedText += GREEK_QUESTION_MARK;
            break;
        default:
        ruinedText += c;
            break;
        }
    }

    text = ruinedText;
}

void
ruinFile(const std::string& filepath)
{
    // Function to ruin file

    // Opens file, reads all code from it
    // and replaces it with ruined one

    std::string fileContent;
    if (!readFromFile(filepath, fileContent))
        return;

    ruinCode(fileContent);
    
    if(writeToFile(filepath, fileContent))
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
