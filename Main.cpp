#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
using namespace std;

void ArithmeticGame()
{
	srand(time(0));
	const int noQs = 5;
	int Score = 0;
	for (int noQs = 0; noQs < 5; noQs++) {
		int ran1 = (rand() % 10) + 1;
		int ran2 = (rand() % 10) + 1;
		int ran3 = (rand() % 2) +1;
		if (ran3 == 1)
		{
			cout << "What is " << ran1 << " + " << ran2 << " ?";
			int answer = ran1 + ran2;
			int Uanswer;
			cin >> Uanswer;
			if (Uanswer == answer)
			{
				cout << "Correct.";
				Score = Score + 1;
			}
			else if (Uanswer != answer)
			{
				cout << "Not correct, the answer is " << answer << " . ";
			}
		}
		else if (ran3 == 2)
		{
			cout << "What is " << ran1 << " - " << ran2 << " ? ";
			int answer = ran1 - ran2;
			int Uanswer;
			cin >> Uanswer;
			if (Uanswer == answer)
			{
				cout << "Correct.";
				Score = Score + 1;
			}
			else if (Uanswer != answer)
			{
				cout << "Not correct, the answer is " << answer << " . ";
			}
		}
	}
	cout << "Congratulations, you got " << Score << " right.";

}
void Mastermind()
{
	srand(time(0));
	int dig1 = (rand() % 9) + 1;
	int dig2 = (rand() % 9) + 1;
	int dig3 = (rand() % 9) + 1;
	int dig4 = (rand() % 9) + 1;
	int NUMBER_OF_ATTEMPTS = 0;
	clock_t start;
	double TimeTaken;
	start = clock();
	cout << "I am thinking of a 4 digit number and you have 10 attempts to guess it. \n";
	for (int NUMBER_OF_ATTEMPTS = 0; NUMBER_OF_ATTEMPTS < 10; NUMBER_OF_ATTEMPTS++)
	{
	 	cout << "Try and guess the number! You have used " << NUMBER_OF_ATTEMPTS << " attempts so far. Good luck! \n";
		int Attempt;
		cin >> Attempt;
		int Adig1;
		int Adig2;
		int Adig3;
		int Adig4;
		int CorrectDigits = 0;
		int RightPlace1 = 0;
		int RightPlace2 = 0;
		int RightPlace3 = 0;
		int RightPlace4 = 0;
		int CorrectandRightPlace = 0;
		int CorrectNotRightPlace = 0;
		if ((Attempt > 0) && (Attempt < 10000))
		{
			Adig1 = Attempt / 1000;
			Adig2 = Attempt - (Adig1 * 1000);
			Adig2 = Adig2 / 100;
			Adig3 = Attempt / 10;
			Adig3 = Adig3 % 10;
			Adig4 = Attempt % 10;
			cout << "Digits are " << Adig1 << " " << Adig2 << " " << Adig3 << " " << Adig4 << " . \n";
			cout << "Correct digits are " << dig1 << "" << dig2 << "" << dig3 << "" << dig4 << "\n";
			if (Adig1 == dig1 && Adig2 == dig2 && Adig3 == dig3 && Adig4 == dig4)
			{
				TimeTaken = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << " All correct in " << TimeTaken << " seconds, well done! \n";
				break;
				// tested, working - correct answer is recognised.
			}
			// could use switch and case here?
			if (Adig1 == dig1)
			{
				CorrectDigits = CorrectDigits + 1;
				RightPlace1 = 1;
				CorrectandRightPlace = CorrectandRightPlace + 1;
			}
			else if (Adig1 == dig2 || Adig1 == dig3 || Adig1 == dig4)
			{
				CorrectNotRightPlace = CorrectNotRightPlace + 1;

			}
			if (Adig2 == dig2)
			{
				CorrectDigits = CorrectDigits + 1;
				RightPlace2 = 1;
				CorrectandRightPlace = CorrectandRightPlace + 1;
			}
			else if (Adig2 == dig1 || Adig2 == dig3 || Adig2 == dig4)
			{
				CorrectNotRightPlace = CorrectNotRightPlace + 1;
			}
			if (Adig3 == dig3)
			{ 
				CorrectDigits = CorrectDigits + 1;
				RightPlace3 = 1;
				CorrectandRightPlace = CorrectandRightPlace + 1;
			}
			else if (Adig3 == dig1 || Adig3 == dig2 || Adig3 == dig4)
			{
				CorrectNotRightPlace = CorrectNotRightPlace + 1;
			}

			if (Adig4 == dig4)
			{
				CorrectDigits = CorrectDigits + 1;
				RightPlace4 = 1;
				CorrectandRightPlace = CorrectandRightPlace + 1;
			}
			else if (Adig4 == dig1 || Adig4 == dig2 || Adig4 == dig3)
			{
				CorrectNotRightPlace = CorrectNotRightPlace + 1;
			}
			int RightPlaces = RightPlace1 + RightPlace2 + RightPlace3 + RightPlace4;
			cout << " " <<CorrectandRightPlace << " right digits, right location \n";
			cout << "" <<CorrectNotRightPlace<< " right digits, wrong location \n";
			TimeTaken = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Time taken: " << TimeTaken << " seconds so far. \n";
			if (NUMBER_OF_ATTEMPTS == 9)
			{
				cout << "Unlucky, you didn't get the answer in time. It was " << dig1 << "" << dig2 << "" << dig3 << "" << dig4 << " . \n";
			}



		}
		else
		{
			cout << "Invalid number, please try again.\n";
		}
		

	}
	TimeTaken = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Time taken overall: " << TimeTaken << " seconds.";


}
int main()
{
	//ArithmeticGame();
	Mastermind();
	system("pause");
	return 0;

}