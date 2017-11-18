/*
 * Files.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: frankycg
 */

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1) /* affect file size, but seems not read or write result */
struct Person {
	char name[50]; /* string would not able to write to file */
	int age;
	double height;
};
#pragma pack(pop)

void error_open_file(string fileName) {
	cout << "Error: not able to open " << fileName << endl;
}

int main() {
	string FILENAME = "output.txt";
	string FILENAME_BIN = "output.bin";
	Person presidentUS = {"Donald Trump", 60, 1.85};
	Person someone = {};

	//// write to a txt file ////
	ofstream outFile;
//	outFile.open(FILENAME, fstream::app); /* if write to append */
	outFile.open(FILENAME.c_str());
	if (outFile.is_open()) {
		outFile << "US population: 400000000     " << endl;
		outFile << "China Population: 1400000000 " << endl; /* other data type as well */
		outFile.close();
	}
	else error_open_file(FILENAME);

	//// write to a binary file ////
	ofstream outFileBin;
	outFileBin.open(FILENAME_BIN.c_str(), ios::binary);
	if (outFileBin.is_open()) {
		outFileBin.write(reinterpret_cast<char *>(&presidentUS), sizeof(Person));
		outFileBin.close();
	}
	else error_open_file(FILENAME_BIN);

	//// read from a txt file ////
	ifstream inFile;
	inFile.open(FILENAME.c_str());
	if (inFile.is_open()) {
		string varName;
		int varValue;
		while (inFile) { /* short hand of !inFile.eof() */
			getline(inFile, varName, ':');
			inFile >> varValue;
			inFile >> ws; /* clean up trailing spaces */
			if (!inFile) break; /* avoid last empty line */
			cout << varName << " is " << varValue << endl;
		}
		inFile.close();
	}
	else error_open_file(FILENAME);

	//// read from a binary file ////
	ifstream inFileBin;
	inFileBin.open(FILENAME_BIN.c_str(), ios::binary);
	if (inFileBin.is_open()) {
		inFileBin.read(reinterpret_cast<char *>(&someone), sizeof(Person));
		cout << someone.name << " is " << someone.age << " years old, and stands ";
		cout << someone.height << "m tall." << endl;
		inFileBin.close();
	}
	else error_open_file(FILENAME_BIN);

	/* 2 - way fstream */
//	fstream inoutFile;
//	inoutFile.open(FILENAME, ios::out);
	return 0;
}
