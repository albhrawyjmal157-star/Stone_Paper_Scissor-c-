#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

enum enGame
{
    Stone = 1,
    Paper = 2,
    Scissor = 3
};
enum enWiner
{
    Player = 1,
    Computer = 2,
    Draw = 3
};

void ReSetScreen()
{
    system("cls");
    system("color 0F");
}
int ReadNumberOfRound()
{
    int NumberRound = 0;

    do
    {
        cout << "PLease Enter A Number 1 To 10 : ";
        cin >> NumberRound;
    } while (NumberRound > 10 || NumberRound < 1);
    return NumberRound;
}
short ReadChoice(int i)
{
    short choice = 0;

    do
    {
        cout << "Round [" << i << "] begins : Your Choice  [1]:Stone, [2]Paper, [3]scissor : ";
        cin >> choice;
    } while (choice > 3 || choice < 1);
    return choice;
}

enGame ChoiceGame(int Number)
{
    return (enGame)Number;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enWiner Winer(enGame ChoicePlayer, enGame choiceComputer, int &ResultPlayer, int &Resultcomputer, int &Draw)
{
    if (ChoicePlayer == choiceComputer)
    {
        Draw++;
        return enWiner::Draw;
    }

    if (
        (ChoicePlayer == enGame::Paper && choiceComputer == enGame::Stone) ||
        (ChoicePlayer == enGame::Stone && choiceComputer == enGame::Scissor) ||
        (ChoicePlayer == enGame::Scissor && choiceComputer == enGame::Paper))

    {
        ResultPlayer++;
        return enWiner::Player;
    }
    else
    {
        Resultcomputer++;
        return enWiner::Computer;
    }
}
string ReturnWiner(enWiner Winer)
{
    switch (Winer)
    {
    case enWiner::Computer:
        Beep(800, 200);
        system("color 4F");
        return " Computer ";
        break;

    case enWiner::Player:
        system("color 2F");
        return " Player ";
        break;
    default:
        system("color 6F");
        return " Draw ";
        break;
    }
}

string ReturnEnumOfChoice(enGame Choice)
{
    switch (Choice)
    {
    case enGame::Paper:
        return " Paper ";
        break;
    case enGame::Scissor:
        return " Scissor ";
        break;
    case enGame::Stone:
        return " Stone ";
        break;
    default:
        return "Unknown";
    }
}

void PrintRound(int Counter, enGame ChoicePlayer, enGame choiceComputer, int &ResultPlayer, int &Resultcomputer, int &Draw)
{
    cout << "-----------------------------Round[" << Counter << "]------------------------------" << endl;
    cout << "Player1 Choice : " << ReturnEnumOfChoice(ChoicePlayer) << endl;
    cout << "Computer Coice : " << ReturnEnumOfChoice(choiceComputer) << endl;
    enWiner Win = Winer(ChoicePlayer, choiceComputer, ResultPlayer, Resultcomputer, Draw);
    cout << "Round Winer : [" << ReturnWiner(Win) << "]" << endl;
    cout << "-------------------------------------------------------------------" << endl;
}
enWiner Win(int ResultPlayer, int Resultcomputer)
{
    if (ResultPlayer > Resultcomputer)
    {
        return enWiner::Player;
    }
    else if (ResultPlayer < Resultcomputer)
    {
        return enWiner::Computer;
    }
    else
    {
        return enWiner::Draw;
    }
}
void PrintFinalResult(int Num, int ResultPlayer, int Resultcomputer, int Draw)
{
    cout << "\n\t\t\t\t ------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t+++ Game Over+++ " << endl;
    cout << "\t\t\t\t ------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t -----------------------[Game Result ]-----------------------------------" << endl;
    cout << "\t\t\t\t Game Round : " << Num << endl;
    cout << "\t\t\t\tPlayer Won Times : " << ResultPlayer << endl;
    cout << "\t\t\t\tComputer Won Times : " << Resultcomputer << endl;
    cout << "\t\t\t\t Draw Times : " << Draw << endl;
    cout << "FinalWiner : " << ReturnWiner(Win(ResultPlayer, Resultcomputer));
}
void ShowGameOverScreen()
{
    bool PlayAgain = true;

    while (PlayAgain)
    {
        int ResultPlayer = 0;
        int Resultcomputer = 0;
        int Draw = 0;
        ReSetScreen();
        int Num = ReadNumberOfRound();

        for (int i = 1; i <= Num; i++)
        {
            int Number = ReadChoice(i);
            enGame ChoicePlayer = ChoiceGame(Number);
            enGame choiceComputer = ChoiceGame(RandomNumber(1, 3));
            PrintRound(i, ChoicePlayer, choiceComputer, ResultPlayer, Resultcomputer, Draw);
        }

        PrintFinalResult(Num, ResultPlayer, Resultcomputer, Draw);

        char Choice;
        do
        {
            cout << "Do You Want To Play Again y/n : ";
            cin >> Choice;

        } while (Choice != 'y' && Choice != 'Y' && Choice != 'n' && Choice != 'N');

        if (Choice == 'n' || Choice == 'N')
        {
            PlayAgain = false;
        }

        cout << "\nThank you for playing!" << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    ShowGameOverScreen();
}