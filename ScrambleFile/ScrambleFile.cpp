#include "ScrambleFile.h"

void ScrambleFile::ScrambleTheFile() {
	std::fstream fs(input_filename, std::ios_base::in | std::ios_base::out);
	std::vector<std::string> words;
	std::string buffer;
	if (fs.is_open()) {
		while (getline(fs, buffer))
			words.push_back(buffer);
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(words.begin(), words.end(), std::default_random_engine(seed));
		std::fstream output_file;
		output_file.open(output_filename, std::fstream::out | std::fstream::trunc);

		for (size_t i = 0; i < words.size(); i++)
			output_file << words[i] << "\n";

		if (output_file.gcount())
			std::cout << "The File was successfully scrambled." << std::endl;

		output_file.close();
	}
	else
		std::cout << "An error has occurred, the file could not be scrabmled." << std::endl;
}

int main()
{
	std::string source = "./data/words.txt";
	std::string output = "ScrambledFile.txt";
	ScrambleFile sf(source, output);
	sf.ScrambleTheFile();
}
