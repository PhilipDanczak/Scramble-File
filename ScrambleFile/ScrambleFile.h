#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

class ScrambleFile {
private:
	std::string input_filename;
	std::string output_filename;
	std::vector<std::string> words;
public:
	ScrambleFile(std::string& source_file, std::string& output_file) :
		input_filename(source_file), output_filename(output_file) {};
	void ScrambleTheFile(void);

};