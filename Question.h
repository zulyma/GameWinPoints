#pragma once

#include <iostream>
#include <vector>

class Question
{
private:
	std::string statement;
	std::vector<std::string> responseOption;
	int validResponse;
	int category;
public:
	void setStatement(std::string statement);
	void setValiddResponse(int validResponse);
	void setCategory(int category);
	std::string getStatement();
	int getValidResponse();
	int getCategory();
	std::vector<std::string> getResponseOption();
	void addResponseOption(std::string itemResponseOption);
	void showQuestion();
};

