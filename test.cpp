#include <gtest/gtest.h>
#include "RPS.h"

namespace {

    class RPSTest : public testing::Test, protected RockPaperScissorGame {

        protected : 

            void SetUp() override {
                srand(time(0)) ;
            }

            void setUsersChoiceValues(char user1Choice) {
                g1.user1->setChoice(user1Choice) ;
                EXPECT_EQ(g1.user1->getChoice(), user1Choice) ;
                g1.user2->getMove() ;
                char user2Choice = g1.user2->getChoice() ;
                EXPECT_TRUE(user2Choice == 'R' || user2Choice == 'P' || user2Choice == 'S') ;
            }

            RockPaperScissorGame g1 ;

    } ;

    // To test the default constructor
    TEST_F(RPSTest, DefaultConstructor) {
        EXPECT_EQ(g1.user1->getScore(), 0) ;
        EXPECT_EQ(g1.user2->getScore(), 0) ;
    }

    // To test the Round Winner with Rock as User's Choice
    TEST_F(RPSTest, RoundWinnerTestWithRock) {
        setUsersChoiceValues('R') ;

        if ( g1.user2->getChoice() == 'R' ) {
            EXPECT_EQ(g1.getRoundWinner(), 0) ;
        }else if ( g1.user2->getChoice() == 'P' ) {
            EXPECT_EQ(g1.getRoundWinner(), -1) ;
        }else{
            EXPECT_EQ(g1.getRoundWinner(), 1) ;
        }

    }

    // To test the Round Winner with Paper as User's Choice
    TEST_F(RPSTest, RoundWinnerTestWithPaper) {
        setUsersChoiceValues('P') ;

        if ( g1.user2->getChoice() == 'R' ) {
            EXPECT_EQ(g1.getRoundWinner(), 1) ;
        }else if ( g1.user2->getChoice() == 'P' ) {
            EXPECT_EQ(g1.getRoundWinner(), 0) ;
        }else{
            EXPECT_EQ(g1.getRoundWinner(), -1) ;
        }

    }

    // To test the Round Winner with Scissors as User's Choice
    TEST_F(RPSTest, RoundWinnerTestWithScissors) {
        setUsersChoiceValues('S') ;

        if ( g1.user2->getChoice() == 'R' ) {
            EXPECT_EQ(g1.getRoundWinner(), -1) ;
        }else if ( g1.user2->getChoice() == 'P' ) {
            EXPECT_EQ(g1.getRoundWinner(), 1) ;
        }else{
            EXPECT_EQ(g1.getRoundWinner(), 0) ;
        }

    }

    // To test the Score Updation by Base Class Player
    TEST_F(RPSTest, ScoreUpdateTest) {
        g1.user1->updateScore() ;
        EXPECT_TRUE(g1.user1->getScore() > g1.user2->getScore() && g1.user1->getScore() == 1) ;
        g1.user2->updateScore() ;
        EXPECT_TRUE(g1.user1->getScore() == g1.user2->getScore() && g1.user2->getScore() == 1) ;
    }

}