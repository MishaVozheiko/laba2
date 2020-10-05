#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void sortString(string &str) 
{ 
	int n = str.size();
	for(int i = 1; i < n; ++i)
	{
		for(int r = 0; r < n-i; r++)
		{
			if(str[r] > str[r+1])
			{
				char temp = str[r];
				str[r] = str[r+1];
				str[r+1] = temp;
			}
		}
	}
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите произвольное предложение:\n";
    string line;
	getline(std::cin, line);

	char* line_c = new char[line.length() + 1];
	std::strcpy(line_c, line.c_str());
	char* words = strtok(line_c, " ");
	line.clear();

	string endLine = "";
	while (words != NULL) {
		string letters, other;
		for (int i = 0; i < strlen(words); i++)
		{
			if ((words[i] >= 65 && words[i] <= 90) || (words[i] >= 97 && words[i] <= 122)) {
				letters += words[i];
				other += "x";
			}
			else {
				other += words[i];
			}
		}
		sortString(letters);
		std::cout << letters << std::endl;
		int k = 0;
		for (int i = 0; i < other.size(); i++)
		{
			if (other[i] == 'x')
				other[i] = letters[k++];
		}
		endLine += other + " ";
		words = strtok(NULL, " ");
	}
	delete[] line_c;
    cout << endLine << endl;
    return 0;
}
