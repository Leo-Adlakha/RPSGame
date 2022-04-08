#include<bits/stdc++.h>
using namespace std;

class Player {

    protected :

        int score ;
        char choice ;

    public :

        Player() {
            this->score = 0 ;
            this->choice = ' ' ;
        }

        // To be overridden in the derived Class

        // Get Player's Current Move
        void virtual getMove() = 0 ;

        // Display Player's Current Move
        void virtual displayChoice() = 0 ;

        // Display Player's Current Score
        void virtual displayScore() = 0 ;

        // update Player's Score
        void updateScore() {
            this->score++ ;
        }

        // Get Player's Current Score
        int getScore() {
           return this->score ;
        }

        // Get Player's Current Move
        char getChoice() {
            return this->choice ;
        }

        void setChoice(char ch) {
            this->choice = ch ;
        }

        virtual ~Player() {} 

} ;

class User: public Player {

    public : 

        void getMove() {
            bool flag = 0 ;
            char ch ;
            do{

                // Taking a valid User Input
                if ( !flag ) {
                    flag = 1 ;
                    cout << "Enter your Choice: " << endl ;
                }else{
                    cout << "You have entered an invalid Choice!\nEnter a correct Choice: " << endl ;
                }
                cout << "(R) for Rock" << endl ;
                cout << "(P) for Paper" << endl ;
                cout << "(S) for Scissors" << endl ;
                cin >> ch ;
            }while ( ch != 'R' && ch != 'P' && ch != 'S' ) ;
            setChoice(ch) ;
        }

        void displayChoice() {
            cout << "Your Choice: " << this->choice << endl ;
        }

        void displayScore() {
            cout << "Your Score: " << this->score << endl ;
        }

} ;

class Computer: public Player {

    public : 

        void getMove() {

            // Generating a random Number for an equi-probable move.
            int randomNumber = rand() % 3 ;
            char choices[3] = {'R', 'P', 'S'} ;
            setChoice(choices[randomNumber]) ; 

        }

        void displayChoice() {
            cout << "Computer's Choice: " << this->choice << endl ;
        }

        void displayScore() {
            cout << "Computer's Score: " << this->score << endl ;
        }

} ;

class RockPaperScissorGame {

    public : 

        // 2 users playing the game
        Player *user1 ;
        Player *user2 ;

        // Initialization
        RockPaperScissorGame() {
            srand(time(0)) ;
            user1 = new User() ;
            user2 = new Computer() ;
        }

        // Get Current Round Winner
        int getRoundWinner() {

            if ( user1->getChoice() == user2->getChoice() ) {
                return 0 ;
            }else{
                if (user1->getChoice() == 'R' && user2->getChoice() == 'S' || 
                    user1->getChoice() == 'S' && user2->getChoice() == 'P' || 
                    user1->getChoice() == 'P' && user2->getChoice() == 'R' ) {
                    return 1 ;
                }else {
                    return -1 ;
                }
            }

        }

        // Function to Play the Game
        void playGame() {

            cout << "Rock, Paper and Scissors Game" << endl ;
            cout << "--------------------------------------" << endl ;

            string str ;
            do{

                // user Choice
                user1->getMove() ;

                // computer's choice
                user2->getMove() ;

                // display choices
                user1->displayChoice() ;
                user2->displayChoice() ;

                // calculate winner
                int winner = getRoundWinner() ;

                // update winner's score
                if ( winner == 1 ) {
                    user1->updateScore() ;
                }else if ( winner == -1 ) {
                    user2->updateScore() ;
                }

                // display scores
                displayScore() ;

                cout << "Do you want to continue playing ?" << endl ;
                cout << "(Y/y) for Yes" << endl ;
                cout << "Type any other value to end the game." << endl ;
                cin >> str ;
            }while ( ( str[0] == 'Y' || str[0] == 'y' ) && str.size() == 1 ) ;

            getWinner() ;

        }

        // Display Current Score
        void displayScore() {
            user1->displayScore() ;
            user2->displayScore() ;
        }

        // Display Final Scores and the Winner of the Game
        void getWinner() {
            cout << "Final Scores" << endl ;
            cout << "--------------------------------------" << endl ;
            displayScore() ;
            if ( user1->getScore() > user2->getScore() ) {
                cout << "You have won the Game." << endl ;
            }else if ( user1->getScore() == user2->getScore() ) {
                cout << "Its a Draw." << endl ;
            }else{
                cout << "The Computer has won the Game." << endl ;
            }
            cout << "--------------------------------------" << endl ;
        }

        ~RockPaperScissorGame() {
            user1 = user2 = NULL ;
            delete user1 ;
            delete user2 ;
        }

} ;