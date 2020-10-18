#include "TestMazeGenerator.h"
#include "Maze2d.h"
#include "Demo.h"
#include "CLI.h"

int main(void)
{
    srand(time(NULL));

    /*========================= TestMazeGenerator =========================*/
    // SimpleMaze2dGenerator sm;
    // MyMaze2dGenerator my;
    // TestMazeGenerator test1;
    // TestMazeGenerator test2;
    // test1.TestMazeGeneratorGenerator(sm);
    // test2.TestMazeGeneratorGenerator(my);


    /*================================ Demo ================================*/
    // Demo demo;
    // demo.run();


    /*================================ CLI =================================*/
    CLI cli(cin, cout);
    cli.start();

    return 0;
}
