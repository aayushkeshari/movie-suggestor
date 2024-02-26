#include <iostream>
#include <string>

class StreamingShow {
private:
    std::string title;
    std::string description;

public:
    StreamingShow() {
        title = "";
        description = "";
    }

    StreamingShow(const std::string& _title, const std::string& _description) {
        title = _title;
        description = _description;
    }

    std::string getTitle() const {
        return title;
    }

    void setTitle(const std::string& _title) {
        title = _title;
    }

    std::string getDescription() const {
        return description;
    }

    void setDescription(const std::string& _description) {
        description = _description;
    }

    virtual void Play() {
        std::cout << "Playing: " << title << std::endl;
    }

    void Details() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Description: " << description << std::endl;
    }
};

class TVShow : public StreamingShow {
private:
    std::string seasonsAndEpisodes[10][24];
    int numSeasons;

public:
    TVShow() : StreamingShow() {
        numSeasons = 0;
    }

    TVShow(const std::string& _title, const std::string& _description, int _numSeasons) : StreamingShow(_title, _description) {
        numSeasons = _numSeasons;
    }

    int getNumSeasons() const {
        return numSeasons;
    }

    void setNumSeasons(int _numSeasons) {
        numSeasons = _numSeasons;
    }

    void Play() override {
        int season, episode;
        std::cout << "Enter the season and episode number to play: ";
        std::cin >> season >> episode;

        if (season >= 1 && season <= numSeasons && episode >= 1 && episode <= 24) {
            std::cout << "Playing: " << seasonsAndEpisodes[season - 1][episode - 1] << std::endl;
        }
        else {
            std::cout << "Invalid season or episode number." << std::endl;
        }
    }

    void Details() {
        StreamingShow::Details();
        std::cout << "Number of Seasons: " << numSeasons << std::endl;
    }
};

class Movie : public StreamingShow {
private:
    std::string openingCredits;

public:
    Movie() : StreamingShow() {
        openingCredits = "";
    }

    Movie(const std::string& _title, const std::string& _description, const std::string& _openingCredits) : StreamingShow(_title, _description) {
        openingCredits = _openingCredits;
    }

    std::string getOpeningCredits() const {
        return openingCredits;
    }

    void setOpeningCredits(const std::string& _openingCredits) {
        openingCredits = _openingCredits;
    }

    void Play() override {
        std::cout << "Playing Opening Credits: " << openingCredits << std::endl;
    }
};

// Function to display details and play a show
void DisplayShow(StreamingShow& show) {
    show.Details();
    show.Play();
}

int main() {
    int choice;
    bool continueTesting = true;

    while (continueTesting) {
        std::cout << "---------------Welcome to Keshari Movies!---------------" << std::endl;
        std::cout << "Press 1 for an instance of Show." << std::endl;
        std::cout << "Press 2 for an instance of Movie." << std::endl;
        std::cout << "Press 3 for an instance of TV Show." << std::endl;
        std::cout << "Press 4 for an instance of a MOVIE declared as a Show." << std::endl;
        std::cout << "Press 5 for an instance of a TV Show declared as a Show." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // This clears the newline character from the input buffer

        StreamingShow* showPtr = nullptr;

        switch (choice) {
        case 1:
            showPtr = new StreamingShow("Generic Show", "A generic streaming show.");
            break;
        case 2:
            showPtr = new Movie("The Social Network", "Harvard sophomore Mark Zuckerberg pursues an idea that propels him to internet success, making him a billionaire, bringing in legal trouble and costing him friendships.", "Directed by David Fincher");
            break;
        case 3:
            showPtr = new TVShow("Scam 1992: The Harshad Mehta Story", "Set in early 90's Bombay, Scam 1992: The Harshad Mehta Story captures the meteoric rise and fall of Harshad Mehta-the flamboyant big bull of the stock market.", 10);
            break;
        case 4:
            showPtr = new Movie("Interstellar", "A team of explorers travel beyond the galaxy through a newly discovered wormhole to discover whether mankind has a future among the stars.", "Directed by Christopher Nolan");
            break;
        case 5:
            showPtr = new TVShow("Narcos", "The story of billionaire druglord Pablo Escobar and Colombia's infamous violent and powerful drug cartels.", 3);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            continue;
        }

        // This displays the details and plays the show
        if (showPtr) {
            DisplayShow(*showPtr);
            delete showPtr; // This frees the allocated memory
        }

        // This asks the user if they wish to continue testing
        char continueChoice;
        std::cout << "Do you wish to continue testing? (y/n): ";
        std::cin >> continueChoice;

        if (continueChoice != 'y' && continueChoice != 'Y') {
            continueTesting = false;
        }
    }

    return 0;
}