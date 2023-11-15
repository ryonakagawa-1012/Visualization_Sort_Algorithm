//
// Created by 中川諒 on 2023/11/13.
//
#include <stdio.h>
#include <handy.h>

int select_algorithm(void){
    int algorithm;
    printf("見たいソートアルゴリズムを選んでください\n\n");
    printf("0: バブルソート\n");
    printf("1: 選択ソート\n");
    printf("2: 挿入ソート\n");
    printf("3: クイックソート\n");
    printf("4: マージソート\n");
    printf("5: ヒープソート\n");
    printf("6: ボゴソート\n\n");

    printf(">>> ");
    scanf("%d", &algorithm);
    return algorithm;
}

int sort_length(void){
    int length;
    printf("ソートする配列の長さを決めてください\n\n");
    printf(">>> ");
    scanf("%d", &length);
    return length;
}

void bubbleSort(int length){

}

void selectionSort(int length){

}

void insertionSort(int length){

}

void quickSort(int length){

}

void mergeSort(int length){

}

void heapSort(int length){

}

void bogoSort(int length){

}
