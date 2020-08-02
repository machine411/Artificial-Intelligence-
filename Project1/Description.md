Your program will need to accept a start cell and goal cell in the grid, and output the path as a set of robot actions (or return the information that the goal cannot be reached). The grids above are in the format that your program must be able to read.

Examples of start and end cells include:

0,1 to 4,14
0,8 to 19,14

though you should devise your own tests to ensure the program behaves correctly for any user input.

Note that the grid file contains number of columns then number of rows as its first line. The start and end cell are specified as X (column), Y (row), where 0,0 is the top-left cell.  The action D (down) increases Y and the action U (up) increases Y.

