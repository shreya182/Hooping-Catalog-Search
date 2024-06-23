#include <string>
#include <fstream>

// DO NOT MODIFY THIS STRUCT TYPE DEFINITION
struct team {
    std::string name; // Name of the team
    std::string owner; // Owner of the team
    int market_value; // Market value of the team
    int num_player; // Number of players in the team
	// Pointer to base address of array that holds all players
    struct player* p;
    float total_ppg; // Total points per game
};

// DO NOT MODIFY THIS STRUCT TYPE DEFINITION
struct player {
    std::string name; // Name of the player
    int age; // Age of the player
    std::string nation; // Nationality of the player
    float ppg; // Points per game of the player
    float fg; // Field goal percentage
};


/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: create_teams
 * Description: This function will dynamically allocate an array of teams
 * Parameters:
 * 		size (int): Size of the array to allocate
 * Returns: Pointer storing the base address of the allocated team array
 * Post-conditions: A team array of requested size is dynamically allocated
 * 		The responsibility of freeing this dynamic memory falls on the function
 * 		caller.
 */
team* create_teams(int size);


/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: populate_team_data
 * Description: This function will fill a single team struct with information
 * 		that is read in from the file
 * Parameters:
 * 		t (team&): Reference to the team struct to be filled with
 * 			information. NOTE: An alternative way to design this function
 *			would be to make it construct a team and return it rather
 *			than accepting one by reference and modifying it. Actually,
 *			that'd be a better idea, but use this prototype anyways as an
 *			opportunity to practice pass-by-reference.
 * 		file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the team struct
 * Post-conditions: The given team struct is populated with the next
 * 		information from the input file. This will also modify the input file's
 * 		state so that subsequent reads operate on whatever data comes after
 * 		the data read to populate the team struct.
 */
void populate_team_data(team& t, std::ifstream& file);


/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: create_players
 * Description: This function will dynamically allocate an array of players
 * Parameters:
 * 		size (int): Size of the array to allocate
 * Returns: Pointer storing the base address of the allocated player array
 * Post-conditions: A player array of requested size is dynamically allocated
 * 		The responsibility of freeing this dynamic memory falls on the function
 * 		caller.
 */
player* create_players(int size);


/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: populate_player_data
 * Description: This function will fill a single player struct with
 * 		information that is read in from the file
 * Parameters:
 * 		p (player&): Reference to the player struct to be filled with
 * 			information. NOTE: An alternative way to design this function
 *			would be to make it construct a player and return it rather
 *			than accepting one by reference and modifying it. Actually,
 *			that'd be a better idea, but use this prototype anyways as an
 *			opportunity to practice pass-by-reference.
 * 		file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the player struct
 * Post-conditions: The given player struct is populated with the next
 * 		information from the input file. This will also modify the input file's
 * 		state so that subsequent reads operate on whatever data comes after
 * 		the data read to populate the player struct.
 */
void populate_player_data(player& p, std::ifstream& file);


/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: delete_info
 * Description: This function will delete all of the dynamically allocated
 * 		memory
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 * Pre-conditions: The team array at the provided pointer is valid and hasn't
 * 		been freed yet
 * Post-conditions: The team array, along with all players inside, is freed
 */
void delete_info(team* teams, int size);

/*
 * Name: displayTeamInfo
 * Description: This function will print all the information for each player from a 
 specific team
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 * Post-conditions: all the team and player information is printed to the terminal
 */
void displayTeamInfo(const team& t, std::ostream& output);

/*
 * Name: output
 * Description: This function will ask the user how they want the information 
 outputted and store their choice
 * Post-conditions: store the users choice for how they want the info displayed
 */
int output();

/*
 * Name: searchName
 * Description: This function will search for a specific team and display
 all the information available about that team
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 *      output preference (int): if the user wants to print to terminal or file
 *      file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the team struct
 * Post-conditions: team information printed to terminal or file
 */
void searchName(team* teams, int size, int output_pref, std::ofstream& outfile);

/*
 * Name: topScorer
 * Description: This function will display the top scorer of each team and their
        points per game
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 *      output preference (int): if the user wants to print to terminal or file
 *      file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the team struct
 * Post-conditions: top scoring players printed to terminal or file
 */
void topScorer(team* teams, int size, int output_pref, std::ofstream& outfile);

/*
 * Name: searchNationality
 * Description: This function will search for players of a specific nationality 
    and display their names and ages.
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 *      output preference (int): if the user wants to print to terminal or file
 *      file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the team struct
 * Post-conditions: players with nationality printed to terminal or file
 */
void searchNationality(team* teams, int size, int output_pref, std::ofstream& outfile);

/*
 * Name: sortTotalPoints
 * Description: This function will sort teams by total points per game and display the
    list.
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 *      output preference (int): if the user wants to print to terminal or file
 *      file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the team struct
 * Post-conditions: list printed to terminal or file
 */
void sortTotalPoints(team* teams, int size, int output_pref, std::ofstream& outfile);