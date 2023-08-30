#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point* array;
    int top;
} Stack;

void initStack(Stack* stack, int capacity) {
    stack->array = (Point*)malloc(sizeof(Point) * capacity);
    stack->top = -1;
}

void push(Stack* stack, int row, int col) { // empilhar
    stack->top++;
    stack->array[stack->top].row = row;
    stack->array[stack->top].col = col;
}

void pop(Stack* stack) { // desempilhar
    stack->top--;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

Point top(Stack* stack) {
    return stack->array[stack->top];
}

int isValidMove(int maze[SIZE][SIZE], int row, int col) {

    if ( ( ((row >= 0) && (row < SIZE)) && ( (col >= 0) && (col < SIZE) ) ) && (maze[row][col] == 0) ){
        return 1;
    }

    return 0;

}

void printMaze(int maze[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int maze[SIZE][SIZE], int row, int col)
{

    maze[row][col] = 3;

    Stack stack;
    initStack(&stack, SIZE * SIZE);

    push(&stack, row, col);

    while(!isEmpty(&stack)) {

        Point current = top(&stack);

        if (current.row == SIZE - 1 && current.col == SIZE - 1) {
            maze[current.row][current.col] = 3;
            return 1;
        }

        int found = 0;

        //int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int newRow;
        int newCol;

        for (int i = 0; i < 4; i++) {

            newRow = current.row;
            newCol = current.col;

            switch (i) {
                case (0):
                    newCol++;
                    break;

                case (1):
                    newRow++;
                    break;

                case (2):
                    newCol--;
                    break;

                case (3):

                    newRow--;
                    break;

                default:
                    maze[newRow][newCol] = 4;
                    break;
            }


            if (isValidMove(maze, newRow, newCol))
            {
                printf("%d  %d\n", newCol, newRow);
                push(&stack, newRow, newCol);
                found = 1;
                maze[newRow][newCol] = 3;
                break;
            }

        }
        if (!found)
        {
            pop(&stack);
        }

    }
    return 0;
}