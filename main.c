#include <stdio.h>
#include <stdlib.h>

#define LAB_WIDTH 4
#define LAB_HEIGHT 4


enum CellType { Empty = 0, Path = 1, Finish = 2 };
typedef enum Direction { NORTH, EAST, SOUTH, WEST} Direction;

typedef struct {

  int location[2];
  Direction direction;

} Player;

Direction* scanForNeighbours(int playerX, int playerY, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) {

  Direction* neighbours = (Direction*)malloc(4 * sizeof(Direction));
  printf("Player location: %d, %d\n", playerX, playerY);

  printf("North = %d\n", labyrinth[playerY - 1][playerX]);
  printf("East = %d\n", labyrinth[playerY][playerX + 1]);
  printf("South = %d\n", labyrinth[playerY + 1][playerX]);
  printf("West = %d\n", labyrinth[playerY][playerX - 1]);
  
  if (playerY != 0 && labyrinth[playerY - 1][playerX] == 1) {
    neighbours[0] = NORTH;
  }

  if (playerX != LAB_WIDTH - 1 && labyrinth[playerY][playerX + 1] == 1) {
    neighbours[1] = EAST;
  }
  
  if (playerY != LAB_HEIGHT - 1 && labyrinth[playerY + 1][playerX] == 1) {
    neighbours[2] = SOUTH;
  }

  if (playerX != 0 && labyrinth[playerY][playerX - 1] == 1) {
    neighbours[3] = WEST;
  }

  return neighbours;
  
}

int singlePathSearch(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]){

  int visitedMask[LAB_HEIGHT][LAB_WIDTH] = {0};

  int *playerX = &player->location[0];
  int *playerY = &player->location[1];

  visitedMask[*playerY][*playerX] = 1;

  Direction* neighbours = scanForNeighbours(*playerX, *playerY, labyrinth);

  int size = 4;
  printf("Amount of neighbours: %d\n\n", size);
  for (int i = 0; i < size; i++) {
    printf("Neighbours:");
    printf("%d\n", (int)neighbours[i]);
  }

  free(neighbours);
  return 0;
}

int BFS(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }

int DFS(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }

int DijkstraSearch(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }

int AStarSearch(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]) { return 0; }



int main() {

  int labyrinthMask[LAB_HEIGHT][LAB_WIDTH] = {{1, 1, 1, 1},
			     {1, 0, 0, 1},
			     {1, 1, 1, 1},
			     {2, 0, 0, 0}};


  Player p1;
  p1.location[0] = 0;
  p1.location[1] = 0;
  p1.direction = SOUTH;

  singlePathSearch(&p1, labyrinthMask);


  return 0;
}
