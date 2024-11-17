#include <stdio.h>
#include <stdlib.h>
#define ROW 100
#define COL 100

void input2DArray(int array[][100], int row, int column){
    for(int i=0;i<row;i++) for(int j=0;j<column;j++) array[i][j]=rand()%1000;
}

void print2DArray(int array[][100], int row, int column){
    printf("======================\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++) printf("[%3d] ",array[i][j]);
        putchar('\n');
    }
}

void addMatrix(int array1[][100], int array2[][100], int res[][100], int row, int column){
    for(int i=0;i<row;i++) for(int j=0;j<column;j++) res[i][j]=array1[i][j]+array2[i][j];
}

void subMatrix(int array1[][100], int array2[][100], int res[][100], int row, int column){
    for(int i=0;i<row;i++) for(int j=0;j<column;j++) res[i][j]=array1[i][j]-array2[i][j];
}

int main(){
    int matrix1[ROW][COL],matrix2[ROW][COL],res[ROW][COL];
    int r,c;
    scanf("%d %d",&r,&c);
    input2DArray(matrix1,r,c);
    input2DArray(matrix2,r,c);
    addMatrix(matrix1,matrix2,res,r,c);
    print2DArray(matrix1,r,c);
    print2DArray(matrix2,r,c);
    print2DArray(res,r,c);
    return 0;
}