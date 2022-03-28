#include "Question.h"

void Question::setStatement(std::string statement)
{
	this->statement = statement;
}

void Question::setValiddResponse(int validResponse)
{
	if (validResponse < this->responseOption.size())
	{
		this->validResponse = validResponse;
	}
	else
	{
		std::cout << "La respuesta válida no está dentro del rango" << std::endl;
	}
}

// Category zero will be not valid
void Question::setCategory(int category)
{
	if (category >= 1 && category <= 5)
	{
		this->category = category;
	}
	else
	{
		std::cout << "La categoría no está dentro del rango" << std::endl;
	}
}
std::string Question::getStatement()
{
	return this->statement;
}
int Question::getValidResponse()
{
	return this->validResponse;
}
int Question::getCategory()
{
	return this->category;
}

std::vector<std::string> Question::getResponseOption()
{
	return this->responseOption;
}
void Question::addResponseOption(std::string itemResponseOption)
{
	this->responseOption.push_back(itemResponseOption);
}

void Question::showQuestion()
{
	std::cout << this->statement << std::endl;
	for (int i = 0; i < responseOption.size(); i++)
	{
		std::cout << i+1 << ". "<< responseOption[i] << std::endl;
	}
}