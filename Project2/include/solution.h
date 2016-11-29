#ifndef _SOLUTION_H
#define  _SOLUTION_H

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

typedef map<char, int> CharInt;
typedef map<int, char> IntChar;

class Solution
{
public:
	int romanToInt(string s);
	string intToRoman(int num);
};

void checkGE900(int& num, string& res);
void checkGE400(int& num, string& res);
void checkGE90(int& num, string& res);
void checkGE40(int& num, string& res);
void checkGE10(int& num, string& res);
void checkL10(int& num, string& res);

#endif