// WinPoints.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Question.h"


std::vector<std::vector<Question>> ReadQuestions()
{
    std::vector<std::vector<Question>> questions;
    Question auxQuestion;
    for (int i = 0; i < 5; i++)
    {
        std::vector<Question> v;
        questions.push_back(v);
    }

    std::string text;
    std::ifstream file("Questions.txt");
    while (std::getline(file, text))
    {
        if (text == "***")
        {
            continue;
        }

        std::stringstream ss1(text);
        int category;
        ss1 >> category;

        std::string statement;
        std::getline(file, statement);

        std::string response1;
        std::getline(file, response1);

        std::string response2;
        std::getline(file, response2);

        std::string response3;
        std::getline(file, response3);

        std::string response4;
        std::getline(file, response4);

        std::getline(file, text);
        std::stringstream ss2(text);
        int validResponse;
        ss2 >> validResponse;

        Question auxQuestion;
        auxQuestion.setCategory(category);
        auxQuestion.setStatement(statement);
        auxQuestion.addResponseOption(response1);
        auxQuestion.addResponseOption(response2);
        auxQuestion.addResponseOption(response3);
        auxQuestion.addResponseOption(response4);
        auxQuestion.setValiddResponse(validResponse-1);
        questions[category - 1].push_back(auxQuestion);

    }

    // Close the file
    file.close();
    return questions;
}

std::vector<Question> selectQuestions(std::vector<std::vector<Question>> allQuestions)
{
    std::vector<Question> result;
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        int randomV = rand() % 5;
        result.push_back(allQuestions[i][randomV]);
    }
    return result;
}

std::vector<Question> setGame()
{
    std::vector<std::vector<Question>> allQuestions = ReadQuestions();
    std::vector<Question> selectedQuestions = selectQuestions(allQuestions);
    return selectedQuestions;
}

std::string askForName()
{
    std::string result;
    std::cout << "Escribe tú nombre" << std::endl;
    std::cout << "Nombre:";
    std::cin >> result;
    return result;
}

void saveGame(std::string name, int level)
{
    std::ofstream output;
    output.open("History.txt", std::ios::app);
    output << name << " " << level - 1<< " Puntos" << std::endl;
    output.close();
    // save game
}

int main()
{
    setlocale(LC_ALL, "spanish");
    std::cout << "Bienvenido a mi juego, Gana puntos con lo que sabes:)" << std::endl;
    setGame();
    std::string name = askForName();
    // true = playing, false = completed
    bool badResponse = false;
    int level = 1;
    std::vector<Question> questions = setGame();
    while (!badResponse && level < 6)
    {
        questions[level - 1].showQuestion();
        std::cout << "5. Abandonar" << std::endl;
        int response;
        std::cin >> response;
        if (response == 5)
        {
            break;
        }
        else if (response - 1 == questions[level - 1].getValidResponse())
        {
            level++;
        }
        else
        {
            badResponse = true;
            level = 1;
        }
    }

    if (badResponse)
    {
        std::cout << "Perdiste :C" << std::endl;
        std::cout << "Obtuviste " << level - 1 << " puntos" << std::endl;
    }
    else
    {
        std::cout << ":) " << std::endl;
        std::cout << "Ganaste " << level -1 << " puntos" << std::endl;
    }
    saveGame(name, level);
    system("pause");
}
