# ConsoleTetris
This is a project that I put together after researching several resources with the goal of making a basic version of Tetris in the conosle. Eventually my goal is to recreate a similar project that uses a basic graphics library like SMFL or SDL to add color to the game. When this project was developed I was primarily trying to gain an understanding of the inner workings of the game logic in Tetris.

Here is a list of the resources that I during the creation of this project:

Youtuber Javidx9's video on Tetris:
https://www.youtube.com/watch?v=8OK8_tHeCIA -> One of the most useful things that I learned from this was how to work with 1 dimensional arrays by using index accessing formulas

Blog post by Javier Lopez:
https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/ - I learned alot from comparing the tetromino storage in this post (4 dimensional array) vs. the previous resource that simply used array manipulation. This project also used the SDL library, so I will investigate this as well.

Windows.h documentation:
https://docs.microsoft.com/en-us/windows/console/console-functions -> I used a console buffer to store output to the screen for Tetris, so this was a common reference point for function calls to the WriteConsoleOutputCharacter() and functions that create console buffers.

C++ reference:
https://en.cppreference.com/w/Main_Page -> I use C++ reference often, but for this I drew on it to gain a better understanding of vectors, bitwise operations, and the thread library. The thread library is reponsible for controlling the game tick of moving the pieces down the board, so I needed to have an understanding of how its sleep_for method operated. Vector's push_back method is used to remove completed lines from the board. Lastly, a bitwise and is used to check for completed lines in the playfield. I wanted to exactly how bitwise ANDs, ORs, and XORs worked.
