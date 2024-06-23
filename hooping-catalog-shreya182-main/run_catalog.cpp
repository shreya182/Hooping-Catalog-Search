#include <iostream>
#include "catalog.h"

int main() {
	std::string file_name;
	std::cout << "What is the file name: ";
	std::cin >> file_name;
	std::ifstream file;
	file.open(file_name);
	if (!file.is_open()){
		std::cout << file_name << "could not be opened" << std::endl;
		return -1;
	}
	std::ofstream outfile;
	int size;
	file >> size;
	team* teams = create_teams(size);
	player* players = create_players(size);

	for (int i = 0; i < size; i++){
		populate_team_data(teams[i], file);
	}
	for (int i = 0; i < size; i++){
		populate_player_data(players[i], file);
	}

	bool playing = true;
	do{
		int option;
		std::cout << "Do you want to search by team name (1), display top scorers (2), search players by nationality (3), Sort by total points per game(4), or quit program(5)?" << std::endl;
		std::cin >> option;
		if (option == 1){
			searchName(teams, size, output(), outfile);
		} else if (option == 2){
			topScorer(teams, size, output(), outfile);
		} else if (option == 3){
			searchNationality(teams, size, output(), outfile);
		} else if (option == 4){
			sortTotalPoints(teams, size, output(), outfile);
		} else if (option == 5){
			playing = false;
			return 0;
		}else {
			std::cout << "Invalid option" << std::endl;
		}
	} while (playing);
}
