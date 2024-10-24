#include <iostream>
#include<cstdlib>
using namespace std;
enum  enGameChoice{ stone=1,paper=2, Scissors=3};
enum enWinner{player=1,computer=2,Draw=3};
struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice playerChoice;
	enGameChoice computerChoice;
	enWinner winner;
	string PlayerChoiceName;
	string ComputerChoiceName;
	string WinnerName;
};
struct stGameResults
{
	short GameRounds = 0;
	short playerWinnerTimes = 0;
	short computerWinnerTimes = 0;
	short DrawTimes = 0;
	enWinner gameWinner;
	string WinnerName;
};
int RondamNumber(int From, int To) {
	int number = 0;
	number = rand() % (To - From + 1) + From;
	return number;
}
void RestartScreen() {
	system("cls");
	system("color 0F");
};
short RoundGame(string Massege ,short from,short to ) {
	short number=0;
	do
	{ 
		cout << Massege;cin >> number;


	} while (!(number>from || number<to));
	return number;
}
enGameChoice playerChoice() {
	short choice;
	cout << "your choice : [1] Stone [2] Paper [3] Scissors : ";
	cin >> choice;
	return (enGameChoice)choice;
}
enGameChoice ComputerChoice() {
	return (enGameChoice)(RondamNumber(1, 3));
}
enWinner WhoWinner(enGameChoice player,enGameChoice computer) {
	if (player==computer)
	{
		 return enWinner::Draw;
	}
	switch (player)
	{
	case enGameChoice::stone:
		if (enGameChoice::paper == computer)
		{ 
			
			return enWinner::computer;
		} 
				break;
	case enGameChoice::paper:
		if (enGameChoice::Scissors == computer) {
			return enWinner::computer;
		}
			break;
	case enGameChoice::Scissors:
		if(enGameChoice::stone==computer){
			return enWinner::computer;
		}
			break;
		break;
	}
		return enWinner::player;
}
void bgColorScreen(enWinner winner,short& playerWinnerTimes,short& computerWinnerTimes ,short& DrawTimes) {
	switch (winner)
	{
	case player:
		system("color 2F");
		playerWinnerTimes++;
		break;
	case computer:
		system("color 4F");
		computerWinnerTimes++;
		break;
	case Draw:
		system("color 6F");
		DrawTimes++;
		break;
	default:
		system("color 5F");
		break;
	}
}
string WinnerName(enWinner winner) {
	string arr[3] = { "Player", "Coumputer", "Draw" };
	return arr[winner - 1];
}
string ChoicesName(enGameChoice choice) {
	string arr[3] = { "Stone", "Paper", "Scissors" };
	return arr[choice - 1];
}
void  PrintRound(stRoundInfo RInfo) {
	cout << "\n____________________ Round [" << RInfo.RoundNumber << "]_____________\n";
	cout << "Player Choice : " << RInfo.PlayerChoiceName << "\n";
	cout << "Computer Choice : " << RInfo.ComputerChoiceName << "\n";
	cout << " Round Winner : " << RInfo.WinnerName << "\n";
	cout << "_______________________________________________\n";
}
enWinner whoWinnerFinshGame(int  player, int computer) {
	if (player==computer)
	{
		system("color 6F");
		return enWinner::Draw;
	}
	else if (player > computer) {
		system("color 2F");
		 return enWinner::player;
	}
	else
	{
		system("color 2F");
		 return enWinner::computer;
	}
}
stGameResults fullResult(int numberRounds,  short playerWinnerTimes, short computerWinnerTimes, short DrawTimes) {
	stGameResults Result;
	Result.GameRounds = numberRounds;
	Result.playerWinnerTimes = playerWinnerTimes;
	Result.computerWinnerTimes = computerWinnerTimes;
	Result.DrawTimes = DrawTimes;
	Result.gameWinner = whoWinnerFinshGame(playerWinnerTimes, computerWinnerTimes);
	Result.WinnerName = WinnerName(Result.gameWinner);
	return Result;
}
stGameResults PlayGame(short NumberRound) {
	stRoundInfo RInfo;
	short playerWinnerTimes = 0, computerWinnerTimes = 0, DrawTimes = 0;
	for (int  i = 1; i <=NumberRound; i++)
	{
		RInfo.RoundNumber = i;
		cout << "\n\n\tRound [" << i << "/" << NumberRound << "] begins \n\n";
		RInfo.playerChoice = playerChoice();
		RInfo.computerChoice = ComputerChoice();
		RInfo.PlayerChoiceName = ChoicesName(RInfo.playerChoice);
		RInfo.ComputerChoiceName = ChoicesName(RInfo.computerChoice);
		RInfo.winner = WhoWinner(RInfo.playerChoice, RInfo.computerChoice);
		bgColorScreen(RInfo.winner,playerWinnerTimes, computerWinnerTimes, DrawTimes);
		RInfo.WinnerName = WinnerName(RInfo.winner);
		PrintRound(RInfo);
	}
	return fullResult(NumberRound, playerWinnerTimes, computerWinnerTimes, DrawTimes);
}
string  Tabs(int n) {
	string t = "";
	for (int i = 0; i < n; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}
void ShowGameOverScreen() 
{ cout << Tabs(2) << "__________________________________________________________\n\n";
cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
cout << Tabs(2) << "__________________________________________________________\n\n";
}
void PrintAllGames(stGameResults GameResults) {
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n"; 
cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
cout << Tabs(2) << "Player won times  : " << GameResults.playerWinnerTimes << endl;
cout << Tabs(2) << "Computer won times : " << GameResults.computerWinnerTimes<< endl;
cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl; 
cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
cout << Tabs(2) << "___________________________________________________________\n"; 

}
void startGame() {
	char PlayAgain = 'y';
	do
	{
		RestartScreen();
		stGameResults Result=PlayGame(RoundGame("\n\n\n  plase Enter Do you want play in 1 to 10 ? ",1,10));
		ShowGameOverScreen();
		PrintAllGames(Result);
		cout << "Do you Play Again ? Y/N? ";cin >> PlayAgain;
	} while (PlayAgain =='y'||PlayAgain=='Y');

}
int main()
{
	srand((unsigned)time(NULL));
	startGame();
	return 0;
}