/*
TITLE: Chapter 5 Exercise 20 - Random Number Guessing Game
FILE NAME: Chapter5Ex20_DAngeloFrancis.cpp
PROGRAMMER: D'Angelo Francis
DATE: November 2024
REQUIREMENTS:
Write a program that generates a random number and asks the user to guess what the number is.

If the user’s guess is higher than the random number, the program should display “Too high, try again.”

If the user’s guess is lower than the random number, the program should display “Too low, try again.”

The program should use a loop that repeats until the user correctly guesses the random number.

Create a second branch and Enhance the program so it keeps a count of the number of guesses the user makes. When the user correctly guesses the random number,

the program should display the number of guesses.*/

#include <iostream>
#include <random>
using namespace std;

random_device numberEngine;
uniform_int_distribution<int> randomInt(0, 100);

int GetRandomNumber();
int GuessNumber();
void HighOrLow(int number, int guess);

int main()
{	
	int choice = 0;

	cout << "Random Number Guessing Game\n";
	cout << "___________________________\n\n";
	cout << "1. PLAY\n";
	cout << "2. QUIT\n\n";

	do
	{
		cout << "Enter your choice (1 or 2): ";
		cin >> choice;

		if (choice < 1 || choice > 2)
		{
			cout << "\n*ERROR* Invalid choice! Try again.\n";
		}
	} while (choice < 1 || choice > 2);

	while (choice == 1)
	{
		int number = GetRandomNumber();
		int guess;
		int guessCount = 0;

		do
		{
			cout << "\n\nGuess #" << ++guessCount;
			guess = GuessNumber();
			HighOrLow(number, guess);
		} while (number != guess);

		cout << "\nCongrats! You guessed the number correctly.\n";
		cout << "Play again?\n\n";
		
		do
		{
			cout << "(Enter 1 for YES, or 2 for NO): ";
			cin >> choice;

			if (choice < 1 || choice > 2)
			{
				cout << "\n*ERROR* Invalid choice! Try again.\n";
			}
		} while (choice < 1 || choice > 2);
	}
	return 0;
}
int GetRandomNumber()
{
	int number = randomInt(numberEngine);
	return number;
}
int GuessNumber()
{
	int guess;
	cout << "\nGuess the number: ";
	cin >> guess;
	return guess;
}
void HighOrLow(int number, int guess)
{
	if (guess > number)
	{
		cout << "\nToo high, try again!\n";
	}
	else if (guess < number)
	{
		cout << "\nToo low, try again!\n";
	}
}