#include <iostream>
#include <fstream>
#include "catalog.h"


team* create_teams(int size) {
	team* teams = new team[size];
	return teams;
}

void populate_team_data(team& t, std::ifstream& file) {
	file >> t.name >> t.owner >> t.market_value >> t.num_player;
	t.p = create_players(t.num_player);

    // Populate player data for the team
    for (int i = 0; i < t.num_player; ++i) {
        populate_player_data(t.p[i], file);
    }
}

player* create_players(int size) {
	player* players = new player[size];
	return players;
}

void populate_player_data(player& p, std::ifstream& file) {
	file >> p.name >> p.age >> p.nation >> p.ppg >> p.fg;
}

void delete_info(team* teams, int size) {
	for (int i = 0; i < size; i++){
		delete []teams[i].p;
	}
	delete []teams;
}
void displayTeamInfo(const team& t, std::ostream& output) {
    output << "Team " << t.name << ":" << std::endl;
    output << "Owner: " << t.owner << std::endl;
    output << "Market Value: " << t.market_value << std::endl;
    output << "Number of players: " << t.num_player << std::endl;
    for (int j = 0; j < t.num_player; j++) {
        output << "Player Name: " << t.p[j].name << std::endl;
        output << "Age: " << t.p[j].age << std::endl;
        output << "Nationality: " << t.p[j].nation << std::endl;
        output << "Points per game: " << t.p[j].ppg << std::endl;
        output << "Field Goal Percentage: " << t.p[j].fg << std::endl;
        output << std::endl;
    }
}
int output(){
	int output_pref;
	std::cout << "How would you like the information displayed? Print to screen (Press 1) or Print to file (Press 2)" << std::endl;
	std::cin >> output_pref;
	return output_pref;
}
void fileout(std::ofstream& outfile){
	std::string outfilename;
	std::cout << "Please provide the desired filename: " << std::endl;
	std::cin >> outfilename;
	outfile.open(outfilename);
}
void searchName(team* teams, int size, int output_pref, std::ofstream& outfile){ 
	std::string name;
	bool found = false;
	if (output_pref == 1){
		std::cout << "Team name: ";
		std::cin >> name;
		//print team info to terminal
		for (int i = 0; i < size; i++) {
            if (teams[i].name == name) {
                displayTeamInfo(teams[i], std::cout);
				found = true;
            }
        }
	} else if (output_pref == 2){ 
		fileout(outfile);
		std::string name;
		std::cout << "Team name: ";
		std::cin >> name;
		//print team info to file
		for (int i = 0; i < size; i++){
			if (teams[i].name == name){
				displayTeamInfo(teams[i], outfile);
				found = true;
			}
		}
	} else {
		std::cout << "Invalid input" << std::endl;
	}
	if (found == false){
			std::cout << "Team with name " << name << " not found." << std::endl;
	} else if (found == true && output_pref == 2){
			std::cout << "Appended requested information to file" << std::endl;
	}
}

void topScorer(team* teams, int size, int output_pref, std::ofstream& outfile){ 
	if (output_pref == 2){
		fileout(outfile);
	}
	for (int i = 0; i < size; i++){ //for each team
		float greatest = 0.0;
		player* topScorer = nullptr;

		for (int j = 0; j < teams[i].num_player; j++){ //for each player
			//find greatest ppg
			if (teams[i].p[j].ppg >= greatest){
				greatest = teams[i].p[j].ppg;
				topScorer = &teams[i].p[j];
			}
		}
		if (output_pref == 1){ //output to terminal
			std::cout << teams[i].name << ": ";
			std::cout << topScorer->name << " " << topScorer->ppg << std::endl;
		} else if (output_pref == 2){ //output to file
			outfile << teams[i].name << ": ";
			outfile << topScorer->name << " " << topScorer->ppg << std::endl;
		}
	}
	if (output_pref == 2){
		std::cout << "Appended requested information to file" << std::endl;
	}
}
void searchNationality(team* teams, int size, int output_pref, std::ofstream& outfile){
	std::string nat;
	bool found = false;
	if (output_pref == 2){
		fileout(outfile);
	} 
	if (output_pref == 1 || output_pref == 2){
		std::cout << "Enter nationality: ";
		std::cin >> nat;
	} else {
		std::cout << "Invalid input" << std::endl;
	}
	//search for matching nationality
	for (int i = 0; i < size; i++){
		for (int j = 0; j < teams[i].num_player; j++){
			if (teams[i].p[j].nation == nat){
				found = true;
				if (output_pref == 1){ //output to terminal
					std::cout << teams[i].p[j].name << " " << teams[i].p[j].age << std::endl;
				} else if (output_pref == 2){ //output to file
					outfile << teams[i].p[j].name << " " << teams[i].p[j].age << std::endl;
				}
			}
		}
	}
	if (found == true && output_pref == 2){
		std::cout << "Appended requested information to file" << std::endl;
	} 
	if (found == false){
		std::cout << "Could not find any " << nat << " players." << std::endl;
	}
}
void sortTotalPoints(team* teams, int size, int output_pref, std::ofstream& outfile){ 
	for (int i = 0; i < size; i++){ //for each team
		double total;
		for (int j = 0; j < teams[i].num_player; j++){ //for each player
			teams[i].total_ppg += teams[i].p[j].ppg;
		}
	}
	//sort greatest to least using swapping
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (teams[j].total_ppg < teams[j + 1].total_ppg){
				team temp = teams[j];
				teams[j] = teams[j+1];
				teams[j+1] = temp;
			}
		}
	} 
	if (output_pref == 2){
		fileout(outfile);
	}
	for (int i = 0; i < size; i++) {
		if (output_pref == 1){ //output to terminal
			std::cout << teams[i].name << ": " << teams[i].total_ppg << " points per game" << std::endl; // Print to console
		} else if (output_pref == 2){ //output to file
			outfile << teams[i].name << ": " << teams[i].total_ppg << " points per game" << std::endl; // Write to file
		}
		//reset total
		teams[i].total_ppg = 0.0;
    }
	if (output_pref == 2){ 
		std::cout << "Appended requested information to file." << std::endl;
	}
}