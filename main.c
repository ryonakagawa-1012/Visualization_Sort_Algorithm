//
// Created by 中川諒 on 2023/11/13.
//

#include "main.h"

int select_algorithm(void); // 見たいアルゴリズムを選ぶCUI画面を表示する関数
int sort_length(void); // ソートする配列の長さを決める関数

void bubbleSort(int Length); // バブルソートを行う関数
void selectionSort(int Length); // 選択ソートを行う関数
void insertionSort(int Length); // 挿入ソートを行う関数
void quickSort(int Length); // クイックソートを行う関数
void mergeSort(int Length); // マージソートを行う関数
void heapSort(int Length); // ヒープソートを行う関数
void bogoSort(int Length); // ボゴソートを行う関数


int main (){
    int algorithm = select_algorithm();

    switch (algorithm) {
        case 0:
            printf("バブルソートを選択しました\n\n");
            bubbleSort(sort_length());
            break;

        case 1:
            printf("選択ソートを選択しました\n\n");
            selectionSort(sort_length());
            break;

        case 2:
            printf("挿入ソートを選択しました\n\n");
            insertionSort(sort_length());
            break;

        case 3:
            printf("クイックソートを選択しました\n\n");
            quickSort(sort_length());
            break;

        case 4:
            printf("マージソートを選択しました\n\n");
            mergeSort(sort_length());
            break;

        case 5:
            printf("ヒープソートを選択しました\n\n");
            heapSort(sort_length());
            break;

        case 6:
            printf("ボゴソートを選択しました\n\n");
            bogoSort(sort_length());
            break;

        default:
            break;
    }

    HgGetChar();
    HgClose();

    return 0;
}