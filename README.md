<h1>Minesweeper</h1>
This is a simple implementation of the classic game Minesweeper in C++ for the console. The game is played on a 10x10 grid where some cells contain mines and others don't. The objective of the game is to uncover all cells that don't contain mines, while avoiding the ones that do. If a player uncovers a cell that contains a mine, the game ends in failure. If the player uncover all cells that don't contain mines, the game ends in victory.

<h2>Requirements</h2>
A C++ compiler (e.g. GCC)
<h2>Compilation and execution</h2>
To compile the code, open a terminal and navigate to the directory where the code is located. Then run the following command:

Copy code
g++ minesweeper.cpp -o minesweeper
To run the game, execute the following command:

bash
Copy code
./minesweeper
<h2>Gameplay</h2>
The game starts with all cells covered. The player can uncover a cell by entering its coordinates (e.g. "1 2"). If the cell contains a mine, the game ends in failure. If the cell doesn't contain a mine, it will be uncovered and its number of neighboring mines will be displayed (e.g. "1" means that there is 1 mine in one of the 8 neighboring cells). If a cell has no neighboring mines, all its neighboring cells will be automatically uncovered. The game ends in victory if all cells that don't contain mines are uncovered.


https://user-images.githubusercontent.com/82110100/217790726-5fff4c99-99da-4513-b604-897cebb667fe.mp4


<h2>Have fun!</h2>
