#include <stdio.h>
#include <stdlib.h>

#define LAB_WIDTH 4
#define LAB_HEIGHT 4

enum CellType { Empty = 0, Path = 1, Finish = 2 };
typedef enum { NORTH, EAST, SOUTH, WEST} Direction;

typedef struct {

  int location[2];
  Direction direction;

} Player;


// TODO: Implement breadth first search.
int BFS(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }

int DFS(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }

int DijkstraSearch(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }

int AStarSearch(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }



int main() {

  int labyrinthMask[LAB_HEIGHT][LAB_WIDTH] = {{1, 1, 1, 1},
			     {0, 0, 0, 1},
			     {1, 1, 1, 1},
			     {2, 0, 0, 0}};


  Player p1;
  p1.location[0] = 0;
  p1.location[1] = 1;
  p1.direction = SOUTH;

  return 0;
}
