
#include "include.h"
#include"board.h"
#include"Solver.h"
#include "input.h"

int cheakInputAndUpdate(Input &input,Solver &solve, board &playArea, int &generationType) {
   // std::cout << "input Index" << input.index << std::endl;
    if (input.index != -1 ) {
       // std::cout << input.index << std::endl;
        
        playArea.cheakClick(input.index, input.rightClick, generationType);
        solve.updateMinesToFind(playArea.grid);

    }
    else {
        solve.updateMinesToFind(playArea.grid);
        return 0;
    }
    input.index = -1;
    return 1;
}



int main()
{
    int win = 0;
    int lose = 0;
    int totalGames=0;
    int switcher = 0;
    int failedPatterns = 0;
    int generationType = 1;
    bool manual = false;
    bool autos = true;
    bool canGuess = true;
    bool textOutput = true;
    sf::RenderWindow window(sf::VideoMode(712, 1160), "SFML works!");
    window.setFramerateLimit(0);
    board playArea(1);
    Solver solve;
    Input input(-1, false);
    float delay = 0;
    sf::Clock delayClock;
    float delay2 = 0;
    sf::Clock delayClock2;
    float delay3 = 0;
    sf::Clock delayClock3;

    sf::Sprite end;
    sf::Texture lostTex;
    lostTex.loadFromFile("images/lost.png");
    sf::Texture winTex;
    winTex.loadFromFile("images/won.png");

    std::fstream outputFile;
    int amountOfguesses = 0;
    

    while (window.isOpen())
    {
        sf::Event event;
        delay = delayClock.getElapsedTime().asSeconds();
        delay2 = delayClock2.getElapsedTime().asSeconds();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (playArea.continueGame == true ) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    playArea.cheakClick(sf::Mouse::getPosition(window), false, generationType);

                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    playArea.cheakClick(sf::Mouse::getPosition(window), true,generationType);

                }
            }
            if (delay2>0.2f) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
                    playArea.debugClick(sf::Mouse::getPosition(window));
                    delayClock2.restart();
                }
                
            }
            //::cout << delay << std::endl;
          
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                playArea.restart();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                playArea.cheatShowMines();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                playArea.cheatHideMines();
            }
        }
        if (delay >= 0.0f) {
            if (playArea.continueGame == true && manual == false) {

                 
                cheakInputAndUpdate(input, solve, playArea, generationType);
                switch (switcher)
                {
                case 0:
                    if (solve.canGuessAgain == true) {
                        input = solve.startingGuesses(playArea.grid);
                    }
                    if (cheakInputAndUpdate(input, solve, playArea, generationType) == 0) {
                        
                    }
                    else {
                       // amountOfguesses++;
                        failedPatterns = 0; 
                        break;
                    }
                    
                    //pattern 1
                    if (solve.canGuessAgain == true) {
                        input = solve.guessPattern1(canGuess, playArea.grid);
                    }
                    if (cheakInputAndUpdate(input, solve, playArea, generationType) == 0) {
                        failedPatterns++;
                        switcher++;
                    }
                    else {
                        amountOfguesses++;
                        failedPatterns = 0;
                        
                    }
                    solve.canGuessAgain = false;
                    break;
                case 1:
                    input = solve.searchPattern1(playArea.grid);
                    if (cheakInputAndUpdate(input, solve, playArea, generationType) == 0) {
                        failedPatterns++;
                        switcher++;
                    }
                    else {
                        //std::cout << "2" << std::endl;
                        failedPatterns = 0; 
                    }
                    break;
                case 2:
                    input = solve.searchPattern2(playArea.grid);
                    if (cheakInputAndUpdate(input, solve, playArea, generationType) == 0) {
                        failedPatterns++;
                        switcher++;
                    }
                    else {
                        //std::cout << "3" << std::endl;
                        failedPatterns = 0; 
                    }
                    break;
                case 3:
                    input = solve.searchPattern3(playArea.grid);
                    if (cheakInputAndUpdate(input, solve, playArea, generationType) == 0) {
                        failedPatterns++;
                        switcher++;
                    }
                    else {
                       // std::cout << "4" << std::endl;
                        failedPatterns = 0; 
                    }
                    break;
                case 4:
                    input = solve.searchPattern4(playArea.grid);
                    if (cheakInputAndUpdate(input, solve, playArea, generationType) == 0) {
                        failedPatterns++;
                        switcher = 0;
                        if (failedPatterns>=50) {
                            playArea.wonOrLost = -1;
                            failedPatterns = 0;
                            
                        }
                        else if (failedPatterns >= 12) {
                           // std::cout << "5" << std::endl;
                            switcher = -1;
                        }
                    }
                    else {
                        failedPatterns = 0; 
                    }
                    break;
                default:
                    //std::cout << "LOLOLOLOkkk " << switcher << std::endl;
                    switcher = 0;
                    solve.canGuessAgain = true;
                    break;
                }
                cheakInputAndUpdate(input, solve, playArea, generationType);
                //std::cout <<"FAILED  "<< failedPatterns << std::endl;
               
               
                
               

               

               
                // for (int i = 0; i < inputs.size(); i++) {
                   //  std::cout << inputs.at(i).index << " inputs" << std::endl;

                 //}

                


            }
            delay = 0;
            delayClock.restart();
        }
        playArea.didWin();

        window.clear();
       
        
       playArea.drawBoard(window);

        
        
        if (playArea.wonOrLost == 1) {
            end.setTexture(winTex);
            end.setOrigin(end.getLocalBounds().width / 2, end.getLocalBounds().height / 2);
            end.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            win++;
            window.draw(end);
           
            
        }
        if (playArea.wonOrLost == -1) {
            end.setTexture(lostTex);
            end.setOrigin(end.getLocalBounds().width / 2, end.getLocalBounds().height / 2);
            end.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            lose++;
            window.draw(end);
            
            
        }

        window.display();

        if (playArea.wonOrLost != 0 && manual == false&& autos==true) {
            totalGames++;
            std::cout << "------------------- " << std::endl;
            std::cout << "won :: " << win << std::endl;
            std::cout << "lost :: " << lose << std::endl;
            std::cout << "total games :: " << totalGames << std::endl;
            do {
                delay3 = delayClock3.getElapsedTime().asSeconds();
            } while (delay3<0.0f);
            delay3 = 0;
            outputFile.open("output.txt", std::fstream::app);
            if (outputFile.is_open()) {
                if (playArea.wonOrLost == 1) {
                outputFile << playArea.countshowncells() << "," << amountOfguesses << ",won" << std::endl;
                }
                else if (playArea.wonOrLost == -1) {
                    outputFile << playArea.countshowncells() << "," << amountOfguesses << ",lost" << std::endl;
                }
                amountOfguesses = 0;
            }
            outputFile.close();
            playArea.restart();
            delayClock3.restart();
            
        }
        if (totalGames >= 10000) {
            while (true) {
            
            }
        }
        
    }

    return 0;
}