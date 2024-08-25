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

int scanForNeighbours(int playerX, int playerY, int labyrinth[LAB_HEIGHT][LAB_WIDTH], Direction* neighbours) {

  printf("Player location: %d, %d\n", playerX, playerY);



  int northNeighbour = -1;
  int eastNeighbour = -1;
  int southNeighbour = -1;
  int westNeighbour = -1;
  

  if (playerY != 0) {
  int northNeighbour = labyrinth[playerY - 1][playerX];
  }
  if (playerX != LAB_WIDTH - 1) {
    eastNeighbour = labyrinth[playerY][playerX + 1];
  }
  if (playerY != LAB_HEIGHT - 1) {
    southNeighbour = labyrinth[playerY + 1][playerX];
  }
  if (playerX != 0) {
    westNeighbour = labyrinth[playerY][playerX - 1];
  }

  printf("North = %d\n", northNeighbour);
  printf("East = %d\n", eastNeighbour);
  printf("South = %d\n", southNeighbour);
  printf("West = %d\n", westNeighbour);

  int neighbourCount = 0;
  
  if (playerY != 0 && northNeighbour > 0) {
    if (northNeighbour == 2) {
      Direction* finalNeighbour = (Direction*)malloc(sizeof(Direction));
      finalNeighbour[0] = NORTH;
      neighbours = finalNeighbour;
      return 1;
    }
    neighbourCount++;
    void* newNeighbours = realloc(neighbours, neighbourCount * sizeof(Direction));
    neighbours = newNeighbours;
    neighbours[neighbourCount - 1] = NORTH;

  }

  if (playerX != LAB_WIDTH - 1 && eastNeighbour > 0) {
    if (eastNeighbour == 2) {
      Direction* finalNeighbour = (Direction*)malloc(sizeof(Direction));
      finalNeighbour[0] = EAST;
      neighbours = finalNeighbour;
      return 1;
    }
    neighbourCount++;
    void* newNeighbours = realloc(neighbours, neighbourCount * sizeof(Direction));
    neighbours = newNeighbours;
    neighbours[neighbourCount - 1] = EAST;
  }
  
  if (playerY != LAB_HEIGHT - 1 && southNeighbour > 0) {
    if (southNeighbour == 2) {
      Direction* finalNeighbour = (Direction*)malloc(sizeof(Direction));
      finalNeighbour[0] = SOUTH;
      neighbours = finalNeighbour;
      return 1;
    }
    neighbourCount++;
    void* newNeighbours = realloc(neighbours, neighbourCount * sizeof(Direction));
    neighbours = newNeighbours;
    neighbours[neighbourCount - 1] = SOUTH;
  }

  if (playerX != 0 && westNeighbour > 0) {
    if (westNeighbour == 2) {
      Direction* finalNeighbour = (Direction*)malloc(sizeof(Direction));
      finalNeighbour[0] = WEST;
      neighbours = finalNeighbour;
      return 1;
    }
    neighbourCount++;
    void* newNeighbours = realloc(neighbours, neighbourCount * sizeof(Direction));
    neighbours = newNeighbours;
    neighbours[neighbourCount - 1] = WEST;
  }

  return neighbourCount;
  
}

int singlePathSearch(Player *player, int labyrinth[LAB_HEIGHT][LAB_WIDTH]){

  int visitedMask[LAB_HEIGHT][LAB_WIDTH] = {0};

  int *playerX = &player->location[0];
  int *playerY = &player->location[1];

  visitedMask[*playerY][*playerX] = 1;

  if (labyrinth[*playerY][*playerX] == 2) {
    return 1;
  }

  Direction* neighbours = (Direction*)malloc(sizeof(Direction));
  int neighbourCount = scanForNeighbours(*playerX, *playerY, labyrinth, neighbours);

  printf("Amount of neighbours: %d\n\n", neighbourCount);
  for (int i = 0; i < neighbourCount; i++) {
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

  int result = singlePathSearch(&p1, labyrinthMask);

  if (result == 1) {
    printf("Found a path!\n");
  } else {
    printf("Did not find a path.\n");
  }


  return 0;
}
