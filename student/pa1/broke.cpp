#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int coins[3];
	int player[3];
	int turn = 0;
	int num_initcoins;
	int num_games;
	int num_turns = 0;
	double avgturnspergame;
	double fairness;
	int num_sims;

	srand(time(0));

	cout << "Enter a Number of Coins for Each Player to Start With" << endl;
	cin >> num_initcoins;

	cout << "Enter The Probability of Heads (between 0 and 1)" << endl;
	cin >> fairness;

	cout << "Enter the Number of Simulations the Program should Run" << endl;
	cin >> num_sims;

	for(int i = 0; i < num_sims; i++)
	{
		coins[0] = num_initcoins;
		coins[1] = num_initcoins;
		coins[2] = num_initcoins;

		while(coins[0] != 0 && coins[1] != 0 && coins[2] != 0)
		{
			for(int j = 0; j < 3; j++)
			{
				double toss = rand()/(double)RAND_MAX;
				if(toss < fairness)
				{
					player[j] = 0;
				}
				else
				{
					player[j] = 1;
				}
			}
			if(player[0] == player[1] && player[2] != player[0])
			{
				coins[2] += 2;
				coins[1]--;
				coins[0]--;
				num_turns++;
			}
			else if(player[1] == player[2] && player[0] != player[1])
			{
				coins[0] += 2;
				coins[1]--;
				coins[2]--;
				num_turns++;
			}
			else if(player[0] == player[2] && player[1] != player[2])
			{			
				coins[1] += 2;
				coins[0]--;
				coins[2]--;
				num_turns++;
			}
			else
			{
				num_turns++;
			}
		}
	}
	avgturnspergame = ((double)num_turns)/num_sims;
	cout << "Average Turns Per Game: " << avgturnspergame << endl;
	return 0;
}



