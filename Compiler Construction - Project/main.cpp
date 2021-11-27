#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<map>


using namespace std;

const int bufferSize = 4143104;  // 4046 KB
const int errorState = 5;

map<string, int> reserveKeywords;

vector<vector<int>> TT; // Transition Table
vector<vector<int>> Advance; // Advance Table
int isFinalIndex = -1;

void lexicalAnalyzer(string filename,string,string);
vector<vector<int>> readTable(string filename);
int getMapping(char character,  int state);
char* readSourceCode(string filename);
void readReserveKeywords(string filename);

bool isAlphabet(char x);
bool isUnderscore(char x);
bool isNumber(char x);
bool isNumber(char x);
bool isExclamation(char x);
bool isEqual(char x);
bool isLess(char x);
bool isGreater(char x);
bool isPlus(char x);
bool isMinus(char x);
bool isCollon(char x);
bool isPlus(char x);
bool isAmpersand(char x);
bool isPersentage(char x);
bool isPersentage(char x);
bool isAsterisk(char x);
bool isDot(char x);
bool isDivided(char x);
bool isExponent(char x);
bool isOr(char x);
bool isSquareStart(char x);
bool isSquareEnd(char x);
bool isMiddleStart(char x);
bool isMiddleEnd(char x);


int main()
{
	string transitionTableFileName = "Transition Table.csv";
	string advanceTableFileName = "Advance.csv";
	string reserveKeywordsFileName = "keywords.txt";
	string errorFileName = "error.txt";
	string tokenFileName = "token.txt";

	readReserveKeywords(reserveKeywordsFileName);

	TT = readTable(transitionTableFileName);
	isFinalIndex = TT[0].size() - 1;

	Advance = readTable(advanceTableFileName);

	lexicalAnalyzer("sourcecode.txt", errorFileName, tokenFileName);

	return 0;
}

bool isAlphabet(char x)
{
	return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z';
}

bool isUnderscore(char x)
{
	return x =='_';
}

bool isNumber(char x)
{
	return x>='0' && x<='9';
}

bool isExclamation(char x)
{
	return x == '!';
}

bool isEqual(char x)
{
	return x == '=';
}

bool isLess(char x)
{
	return x == '<';
}

bool isGreater(char x)
{
	return x == '>';
}

bool isMinus(char x)
{
	return x == '-';
}

bool isCollon(char x)
{
	return x == ':';
}

bool isPlus(char x)
{
	return x == '+';
}

bool isAmpersand(char x)
{
	return x == '&';
}

bool isPersentage(char x)
{
	return x == '%';
}

bool isAsterisk(char x)
{
	return x == '*';
}

bool isDot(char x)
{
	return x == '.';
}

bool isDivided(char x)
{
	return x == '/';
}

bool isExponent(char x)
{
	return x == 'E';
}

bool isOr(char x)
{
	return x == '|';
}

bool isSquareStart(char x)
{
	return x == '[';
}

bool isSquareEnd(char x)
{
	return x == ']';
}

bool isMiddleStart(char x)
{
	return x == '{';
}

bool isMiddleEnd(char x)
{
	return x == '}';
}


vector<vector<int>> readTable(string filename)
{
	vector<vector<int>> TT;
	ifstream fin(filename);
	char dummy{};
	int x;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			vector<int> row;
			dummy = {};
			while (dummy != '\n' && !fin.eof())
			{
				fin >> x;
				row.push_back(x);
				fin.get(dummy);
			}
			TT.push_back(row);
		}
		fin.close();
	}
	else
	{
		cout << "Transition Table File Not Found" << endl;
	}
	return TT;
}


int getMapping(char character,int state)
{
	if (!(state == 10 || state == 12 || state==6 || state==16 || state==46) && isAlphabet(character))
	{
		return 0;
	}
	else
		if ((state==1 || state == 2 || state == 3 || state==0) && isUnderscore(character))
		{
			return 1;
		}
		else
			if((state==0 || state == 1 || state == 12 || state==10 || state==11 || state == 12 || state == 15 || state == 14 || state == 16 || state==9 || state==18) && isNumber(character))
			{
				return 2;
			}
			else
				if (isExclamation(character))
				{
					return 3;
				}
				else
					if ((state == 0 || state == 7 || state==4 || state==8) && isEqual(character))
					{
						return 4;
					}
					else
						if (isLess(character))
						{
							return 5;
						}
						else
							if ((state==0 || state==49 || state==6 || state==7) &&isGreater(character))
							{
								return 6;
							}
							else
								if ((state==0 ||state==18 || state==7 || state== 14) && isPlus(character))
								{
									return 7;
								}
								else
									if ((state==46 || state==0 || state==7) && isCollon(character))
									{
										return 8;
									}
									else
										if ((state==0 || state==9 || state==14) && isMinus(character))
										{
											return 9;
										}
										else
											if (isAmpersand(character))
											{
												return 10;
											}
											else
												if (isPersentage(character))
												{
													return 11;
												}
												else
													if (isAsterisk(character))
													{
														return 12;
													}
													else
														if ((state==0) && isDivided(character))
														{
															return 13;
														}
														else
															if (state==10 && isDot(character))
															{
																return 14;
															}
															else
																if ((state == 10 || state == 12) && isExponent(character))
																{
																	return 15;
																}
																else
																	if (state==0 && isMiddleStart(character))
																	{
																		return 16;
																	}
																	else
																		if (state == 0 && isMiddleEnd(character))
																		{
																			return 17;
																		}
																		else
																			if (state == 0 && isSquareStart(character))
																			{
																				return 18;
																			}
																			else
																				if (state ==0 && isSquareEnd(character))
																				{
																					return 19;
																				}
																				else
																					if ((state==0 || state==17) && isOr(character))
																					{
																						return 20;
																					}
																					else
																						if (state==1 && !isAlphabet(character) && !isNumber(character) && !isUnderscore(character))
																						{
																							return 21;
																						}
																						else
																							if (state==2 && !isAlphabet(character) && !isNumber(character) && !isUnderscore(character))
																							{
																								return 22;
																							}
																							else
																								if (state == 4 && !isEqual(character))
																								{
																									return 23;
																								}
																								else
																									if (state == 6 && !isLess(character) && !isGreater(character))
																									{
																										return 24;
																									}
																									else
																										if (state == 7 && !isLess(character) && !isGreater(character) && !isPlus(character) && !isEqual(character) && !isCollon(character))
																										{
																											return 25;
																										}
																										else
																											if (state == 8 && !isEqual(character))
																											{
																												return 26;
																											}
																											else
																												if (state == 46 && !isCollon(character))
																												{
																													return 27;
																												}
																												else
																													if (state == 9 && !isMinus(character))
																													{
																														return 28;
																													}
																													else
																														if (state == 18 && !isPlus(character))
																														{
																															return 29;
																														}
																														else
																															if (state == 11 && !isAmpersand(character))
																															{
																																return 30;
																															}
																															else
																																if (state == 49 && !isGreater(character))
																																{
																																	return 31;
																																}
																																else
																																	if (state == 16 && !isNumber(character))
																																	{
																																		return 32;
																																	}
																																	else
																																		if (state == 17 && !isOr(character))
																																		{
																																			return 33;
																																		}
																																		else
																																			if (state == 10 && !isExponent(character) && !isNumber(character) && !isDot(character))
																																			{
																																				return 34;
																																			}
																																			else
																																				if (state==12 && !isNumber(character))
																																				{
																																					return 35;
																																				}
																																				else
																																				{
																																					return -1;
																																				}

}

void generateTokens(char* inputBuffer,string errorfile,string tokenfile)
{
	ofstream foute(errorfile);
	ofstream foutt(tokenfile);

	int f = 0;
	
	while (inputBuffer[f]!='\0')
	{
		string lexeme;

		if (inputBuffer[f] == ' ' || inputBuffer[f] == '\t')
		{
			f++;
			continue;
		}
		int state = 0; // Start State
		char character = inputBuffer[f];
		int map = getMapping(character, state);

		lexeme += character;

		while (!TT[state][isFinalIndex])
		{
			if (map == -1)
			{
				f++;
				break;
			}
			if (Advance[state][map])
			{
				f += 1;
			}

			state = TT[state][map]; // Update the new state

			if (state == errorState)
			{
				break;
			}

			if (!TT[state][isFinalIndex])
			{
				character = inputBuffer[f];
				map = getMapping(character, state);
				if (map == -1)
				{
					break;
				}
				if (character != ' ' && Advance[state][map])
				{
					lexeme += character;
				}
			}
		}
		if (state == 19 && reserveKeywords.count(lexeme)) 
		{
			foutt<<"< "<< lexeme <<", "<<" keyword"<<" >"<< endl;
		}
		else
			if (state == 19 && reserveKeywords.count(lexeme)==0)
			{
				foute << "< " << lexeme << ", " << "error" << " >" << endl;
			}
		else
			if (state == 5 || map==-1)
			{
				foute << "< " << lexeme << ", " << "error" << " >" << endl;
			}
			else
			{
				if (state == 36)
				{
					foutt << "< " << lexeme << ", " << "constant" << " >" << endl;
				}
				else
					if (state == 38 || state == 39 || state == 40 || state == 41 || state == 35 || state == 24)
					{
						foutt << "< " << lexeme << ", " << "punctuation" << " >" << endl;
					}
					else
						if (state == 20)
						{
							foutt << "< " << lexeme << ", " << "identifier" << " >" << endl;
						}
					else
					{
						foutt << "< " << lexeme << ", " << "operator" << " >" << endl;
					}
			}
	}	
	
}

char* readSourceCode(string filename)
{
	ifstream fin(filename);
	char* inputBuffer = nullptr;
	if (fin.is_open())
	{
		inputBuffer = new char[bufferSize] {'\0'};
		char x = {};
		int i = 0;
		while (x=fin.get())
		{
			if (x == EOF) {
				break;
			}
			if (x != '\n')
			{
				inputBuffer[i] = x;
				i++;
			}
			if (x != EOF && i == bufferSize)
			{
				delete[]inputBuffer;
				inputBuffer = nullptr;
				cout << "Error: Buffer Overflowed" << endl;
				return inputBuffer;
			}
		}
		return inputBuffer;
	}
	else
	{
		cout << "Source Code File Not Found" << endl;
	}
	return inputBuffer;
}

void lexicalAnalyzer(string filename,string errorfile,string tokenfile)
{
	char* inputBuffer = readSourceCode(filename);
	generateTokens(inputBuffer,errorfile,tokenfile);
}

void readReserveKeywords(string filename)
{
	ifstream fin(filename);

	if (fin.is_open())
	{
		string word;
		while (fin >> word) {
			reserveKeywords.insert({ word,1 });
		}
	}
	else
	{
		cout << "Keywords file not found" << endl;
	}
}