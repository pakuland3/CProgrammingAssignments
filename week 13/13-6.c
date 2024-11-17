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

void multiMatrix(int array1[][100], int array2[][100],int res[][100], int r1, int c1, int c2){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            res[i][j]=0;
            for(int k=0;k<c1;k++) res[i][j]+=array1[i][k]*array2[k][j];
        }
    }
}

int main(){
    int matrix1[ROW][COL],matrix2[ROW][COL],res[ROW][COL];
    int r1,c1=0,r2=1,c2;
    while(c1!=r2){
        printf("r1, c1, r2, c2를 순서대로 입력해주세요.\n");
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        if(c1!=r2) printf("곱셈이 불가능한 조합입니다.\n다시 입력해주세요.\n");
    }
    input2DArray(matrix1,r1,c1);
    input2DArray(matrix2,r2,c2);
    multiMatrix(matrix1,matrix2,res,r1,c1,c2);
    print2DArray(matrix1,r1,c1);
    print2DArray(matrix2,r2,c2);
    print2DArray(res,r1,c2);
    return 0;
}