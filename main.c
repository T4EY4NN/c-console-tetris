#include <stdio.h>
#include <windows.h>
// 맵 크기 변수
#define STAGE_WIDTH 10
#define STAGE_HEIGHT 20

HANDLE hConsoleOut;
void initConsole();
void drawAt(int x, int y, const char* str);


void initStage();

int main() {
    initConsole();
    initStage();
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
// Console 상 위치 pos에 str을 그린다.
void drawAt(int x, int y, const char* str) {
    SetConsoleCursorPosition(hConsoleOut, (COORD){x,y});
    printf(str);
}
// STAGE_WIDTH/HEIGHT 크기의 맵을 그린다.
// stageInfo는 x 한 칸을 1의 크기로, rendering 시에는 한 칸을 2의 크기로 만든다.
void initStage() {
    // "██" 블록 랜더링용 text
    for (int i = 0; i < STAGE_HEIGHT+1; i++) {
        drawAt(0, i, "│");
        drawAt(1+2*STAGE_WIDTH, i, "│");
    }
    drawAt(0, STAGE_HEIGHT+1, "└");
    for (int i = 1; i <= 2*STAGE_WIDTH; i++)    // block 개수 * 2
        drawAt(i, STAGE_HEIGHT+1, "─");
    printf("┘");
}
