#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int get_score(string word);
string get_winner(int score_one, int score_two);

int main(void)
{
    int player_one = get_score(get_string("Player 1: "));
    int player_two = get_score(get_string("Player 2: "));

    printf("%s\n", get_winner(player_one, player_two));
    return 0;
}

int get_score(string s)
{
	const int POINTS[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10,
    };

    int score = 0;
    for (int i = 0; s[i] != '\0'; i++)
	{
		if (isupper(s[i]))
			score += POINTS[s[i] - 'A'];
		else if (islower(s[i]))
			score += POINTS[s[i] - 'a'];
	}
	return score;
}

string get_winner(int p1, int p2)
{
	if (p1 > p2)
		return "Player 1 wins!";
	else if (p2 > p1)
		return "Player 2 wins!";
	return "Tie!";
}
