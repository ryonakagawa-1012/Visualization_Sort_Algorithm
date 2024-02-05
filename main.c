//
// Created by 中川諒 on 2023/11/13.
//

#include "main.h"

int select_algorithm(void); // 見たいアルゴリズムを選ぶCUI画面を表示する関数
int sort_length(void); // ソートする配列の長さを決める関数

int sort_length_for_СталинСорт(void); // ソートする配列の長さを決める関数(スターリンソート用)

void bubbleSort(int Length); // バブルソートを行う関数
void selectionSort(int Length); // 選択ソートを行う関数
void insertionSort(int Length); // 挿入ソートを行う関数
void quickSort(int Length, int Pivot); // クイックソートを行う関数
void mergeSort(int Length); // マージソートを行う関数
void heapSort(int Length); // ヒープソートを行う関数
void bogoSort(int Length); // ボゴソートを行う関数
void Ста́линСорт(int Length); // スターリンソートを行う関数


int main (){
    int algorithm = -1;

    while (algorithm < 0 || 5 < algorithm){
        algorithm = select_algorithm();
    }

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

//        case 3:
//            printf("クイックソートを選択しました\n\n");
//            int length = sort_length();
//            int pivot = -1;
//            while (pivot < 0 || length < pivot) {
//                printf("ピボットの位置を決めてください(%d以下)\n", length);
//                printf(">>> ");
//                scanf("%d", &pivot);
//            }
//            quickSort(length, pivot);
//            break;

        case 3:
            printf("マージソートを選択しました\n\n");
            mergeSort(sort_length());
            break;

//        case 5:
//            printf("ヒープソートを選択しました\n\n");
//            heapSort(sort_length());
//            break;

        case 4:
            printf("ボゴソートを選択しました\n\n");
            bogoSort(sort_length());
            break;

        case 5:
            printf("Вы выбрал Ста́линСорт\n\n");
            Ста́линСорт(sort_length_for_СталинСорт());
            break;

        default:
            break;
    }

    HgGetChar();
    HgClose();

    return 0;
}