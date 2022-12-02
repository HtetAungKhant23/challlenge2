//
// Created by HtetAungKhant on 11/30/2022.
// challenge2
// day3
//
#include "stdio.h"
#include "stdlib.h"

//int num[13];
//int number=0;
//int chNum=0;
char c;
char cArr[10000];
char cArr2[10000];
char searchArr[10];
char searchArr2[10];
int index1=0;
int index2=0;
int tempIdx=0;
int idx=0;

// try it again with array;
int varIntIdx=0;
int varIntArrIdx=0;
int varIntFunIdx=0;
// try it again with array;


struct database{

    int forInt;
    int forChar;
    int forVoid;
    int forFloat;
    int forDouble;
    int forStruct;
    int forIntPointer;
    int forIntPointerArray;
    int forCharPointer;
    int forCharPointerArray;
    int forStructPointer;
    int forFilePointer;
    int forIntFun;
    int forVoidFun;
    int forIntArray;
    int forCharArray;
    int forStructArray;
    int forIf;
    int forElseIf;
    int forElse;
    int forWhile;
    int forLoop;
    int forReturn;

};

struct database db1;
struct database db2;

struct var{

    char forInt[20];
    char forIntArr[20];
    char forIntPointer[20];
    char forChar[20];
    char forCharArr[20];
    char forCharPointer[20];
    char forFloat[20];
    char forFloatArr[20];
    char forDouble[20];
    char forDoubleArr[20];
    char forStruct[20];
    char forFile[20];
    char forFun[20];
    char forVoidFun[20];

}varDb[100];

struct var varDb2[100];

int sizeOfArr(char arr[]);
void searchingDataType(char arr[],int size,struct database d1,struct var varD[]);
void searchingIntVar(char array[], int varForInt, struct var vaDint[]);
void searchingIntFunVar(char array[], int varForIntFun, struct var vaDIntFun[]);

//int compareVarName(struct var n1[],int db1Size,struct var n2[],int db2Size);
int compareVarName(char n1[],char n2[]);
void percentageOfIntVar(int v1IntIdx);


int main(){

    FILE *fptr;
    fptr = fopen("ncc.txt","r");
    if(fptr==NULL){
        printf("File cannot open!");
        exit(1);
    }
    printf("\n");
    while (1){
        c = getc(fptr);
        cArr[index1] = c;
        if(c == EOF){
            break;
        } else{
            printf("%c",c);
        }
        index1++;
    }
    fclose(fptr);
    printf("\n\n");

    FILE *fptr1;
    fptr1 = fopen("ncc1.txt","r");
    if(fptr1==NULL){
        printf("File cannot open!");
        exit(1);
    }
    printf("\n");
    while (1){
        c = getc(fptr1);
        cArr2[index2] = c;
        if(c == EOF){
            break;
        } else{
            printf("%c",c);
        }
        index2++;
    }
    fclose(fptr);
    printf("\n\n");

    searchingDataType(cArr,index1,db1,varDb);

    int varDb1IntIdx = varIntIdx;
    int varDb1IntArrIdx = varIntIdx;
    int varDb1IntFunIdx = varIntIdx;

    varIntIdx=0;
    varIntArrIdx=0;
    varIntFunIdx=0;

    printf("\n\n");
    searchingDataType(cArr2,index2,db2,varDb2);


//    float varNameSameForInt=0;
//
//    printf("for db1 = %d\n",varDb1IntIdx);
//    printf("for db2 = %d\n",varIntIdx);
//
//    for(int i=0; i<varIntIdx; i++){
//        for(int j=0; j<varDb1IntIdx; j++){
//            int result = compareVarName(varDb2[i].forInt,varDb[j].forInt);
//            if(result==1){
//                varNameSameForInt++;
//            }
//        }
//    }
//
//    printf("varNameSameForInt = %f\n",varNameSameForInt);
//
//    float final = (varNameSameForInt * 100) / (varDb1IntIdx + varIntIdx);
//
//    printf("varName same for int percent = %f\n",final);

    percentageOfIntVar(varDb1IntIdx);

    return 0;
}

void searchingDataType(char arr[],int size,struct database d1,struct var varD[]) {

    tempIdx=0;
    varIntIdx=0;
    varIntArrIdx=0;
    varIntFunIdx=0;

    for (int ii = 0; ii < size + 1; ii++) {
        if (arr[ii] == ' ' || arr[ii] == '\n') {
            tempIdx = ii;

            if (arr[tempIdx + 1] == 'i' && arr[tempIdx + 2] == 'n' && arr[tempIdx + 3] == 't' && arr[tempIdx + 4] == ' ' || arr[tempIdx + 4] == '*') {

                d1.forInt++;

                for (int j = 0; j < 3; j++) {
                    searchArr[j] = arr[tempIdx + j + 1];
                }

                int tempId = tempIdx + 4;

                searchingIntVar(arr,tempId,varD);

                while (arr[tempId] != '=' && arr[tempId] != ';') {

                    if (arr[tempId] == '*') {
                        d1.forIntPointer++;
                    } else if (arr[tempId] == '[') {
                        d1.forIntArray++;

                    } else if(arr[tempId] == '('){
                        d1.forIntFun++;
                        searchingIntFunVar(arr,tempId,varD);
                    }
                    tempId++;
                }
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%c", searchArr[i]);
    }

//    if(d1.forIntArray > 0) {
//        d1.forIntArray--;
//    }

    d1.forInt = d1.forInt - d1.forIntArray - d1.forIntPointer - d1.forIntFun;

    printf(" ");
    printf("(db.forInt) = %d\n", d1.forInt);
    printf("db.forIntArr = %d\n", d1.forIntArray);
    printf("db.forIntPointer = %d\n", d1.forIntPointer);
    printf("db.forIntFunction = %d\n", d1.forIntFun);


    for(int i=0; i<varIntFunIdx; i++) {
        printf("db.forIntFunVar = %s\n", varD[i].forFun);
    }

    for(int i=0; i<varIntIdx; i++) {
        printf("db.forIntVar = %s\n", varD[i].forInt);
    }

}

void searchingIntVar(char array[], int varForInt, struct var vaDInt[]){

    while (array[varForInt] != ';' && array[varForInt] != '(' && array[varForInt] != '['){

        if(array[varForInt] == '='){

            int tt = varForInt - 1;
            int te = 0;

            while (array[tt] != ' '){
                te++;
                tt--;
            }
            printf("%d\n",te);

            int tr=0;
            tr = varForInt - te - 1;
            int j=0;

            for(int i=tr; i<varForInt; i++){
                vaDInt[varIntIdx].forInt[j]=array[i];
                j++;
                printf("%c",array[i]);
            }

            varIntIdx++;
        }

        varForInt++;
    }

}

void searchingIntFunVar(char array[], int varForIntFun, struct var vaDIntFun[]){

    int tt = varForIntFun - 1;
    int te = 0;

    while (array[tt] != ' '){
        te++;
        tt--;
    }
    printf("%d\n",te);

    int tr=0;
    tr = varForIntFun - te -1;
    int j=0;

    for(int i=tr; i<varForIntFun; i++){
        vaDIntFun[varIntFunIdx].forFun[j]=array[i];
        j++;
        printf("%c",array[i]);
    }

    varIntFunIdx++;

}

int sizeOfArr(char arr[]){
    int size=0;
    while (arr[size] != '\0'){
        size++;
    }
    return size;
}

int compareVarName(char n1[],char n2[]){

    int size1= sizeOfArr(n1);
    int size2= sizeOfArr(n2);

    if(size1 != size2){
        return -1;
    }

    for(int i=0; i<size1; i++){
        if(n1[i] != n2[i]){
            return -1;
        }
    }
    return 1;
}

void percentageOfIntVar(int v1IntIdx){

    float varNameSameForInt=0;

    printf("for db1 = %d\n",v1IntIdx);
    printf("for db2 = %d\n",varIntIdx);

    for(int i=0; i<varIntIdx; i++){
        for(int j=0; j<v1IntIdx; j++){
            int result = compareVarName(varDb2[i].forInt,varDb[j].forInt);
            if(result==1){
                varNameSameForInt++;
            }
        }
    }

    printf("varNameSameForInt = %f\n",varNameSameForInt);

    float final = (varNameSameForInt * 100) / (v1IntIdx + varIntIdx);

    printf("varName same for int percent = %f\n",final);



}
