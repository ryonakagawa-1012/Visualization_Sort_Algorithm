//
// Created by 中川諒 on 2023/11/22.
//

#ifndef SORT_ALGORITHM_MAIN_H
#define SORT_ALGORITHM_MAIN_H

#include <stdio.h>
#include <handy.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_X 1000.0
#define WINDOW_Y 600.0

#define TRUE 1
#define FALSE 0

typedef struct {
    double x; // 棒グラフの左下隅のx座標
    double y; // 棒グラフの左下隅のy座標
    double width; // 棒グラフの幅
    double height;  // 棒グラフの高さ
} bar_graph;

typedef struct {
    double x; // 棒グラフの左下隅のx座標
    double y; // 棒グラフの左下隅のy座標
    double width; // 棒グラフの幅
    double height;  // 棒グラフの高さ
    int is_удалять; // True: 棒グラフを赤くする, False: 棒グラフを黒くする
} bar_graph_for_СталинСорт;

#endif //SORT_ALGORITHM_MAIN_H
