#include <stdio.h>
#include <windows.h>
#include "block.c"
#include <time.h>
// 맵 크기 변수
#define STAGE_WIDTH 10
#define STAGE_HEIGHT 20

HANDLE hConsoleOut;
void initConsole();
void drawAt(int x, int y, const char* str);

void initStage();
#define EMPTY 0
#define WALL 1
#define BLOCK 2
int stageInfo[STAGE_HEIGHT+1][STAGE_WIDTH+2] = {EMPTY,}; // stageInfo[y][x]: stage 상태 관리 배열
void debugStage() {
    for (int y = 0; y < STAGE_HEIGHT+1; y++) {
        drawAt(2*STAGE_WIDTH+3, y, "");
        for (int x = 0; x < STAGE_WIDTH+2; x++) {
            printf("%d", stageInfo[y][x]);
        }
    }
}

typedef struct {
    int idx;
    int x;
    int y;
} ActiveBlock;
void drawBlock(ActiveBlock* curBlock);
void spawnBlock(ActiveBlock *curBlock);

int main() {
    srand(time(NULL));
    initConsole();
    initStage();
        debugStage();

    ActiveBlock block;
    spawnBlock(&block);
    drawBlock(&block);
                Sleep(5000);
}
// Console의 handle을 얻고, cursor를 비가시화한다.
void initConsole() {

    // 출력 UTF-8
    SetConsoleOutputCP(CP_UTF8);

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // cursor 투명화 처리
    CONSOLE_CURSOR_INFO curCursorInfo;
    GetConsoleCursorInfo(hConsoleOut, &curCursorInfo);
    curCursorInfo.bVisible = 0;
    SetConsoleCursorInfo(hConsoleOut, &curCursorInfo);
}
// Console 상 위치 (x,y)에 str을 그린다.
void drawAt(int x, int y, const char* str) {
    SetConsoleCursorPosition(hConsoleOut, (COORD){x,y});
    printf(str);
}
// Console 상에 STAGE_WIDTH/HEIGHT 크기의 맵을 그리고 stageInfo에 반영.
void initStage() {
    for (int i = 0; i < STAGE_HEIGHT; i++) {
        drawAt(0, i, "│");
        drawAt(1+2*STAGE_WIDTH, i, "│");
        stageInfo[i][0] = WALL;
        stageInfo[i][1+STAGE_WIDTH] = WALL;
    }
    drawAt(0, STAGE_HEIGHT, "└");
    stageInfo[STAGE_HEIGHT][0] = WALL;
    // stageInfo는 x 한 칸을 1의 크기로,
    // Console 상에 rendering 시에는 한 칸을 2의 크기로 만든다.
    for (int i = 1; i <= STAGE_WIDTH; i++) {    // block 개수 * 2
        drawAt(2*i-1, STAGE_HEIGHT, "──");
        stageInfo[STAGE_HEIGHT][i] = WALL;
    }
    printf("┘");
    stageInfo[STAGE_HEIGHT][STAGE_WIDTH+1] = WALL;
}
void drawBlock(ActiveBlock* curBlock) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blockModel[curBlock->idx][i][j] == 1)
                drawAt(2*(curBlock->x+j), curBlock->y+i, "██");
        }
    }
}
void spawnBlock(ActiveBlock *curBlock) {
    curBlock->idx = 4*(rand() % 7);
    curBlock->x = STAGE_WIDTH/2-1;
    curBlock->y = 0;
}