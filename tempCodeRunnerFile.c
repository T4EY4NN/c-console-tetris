) {
    SetConsoleCursorPosition(hConsoleOut, (COORD){x,y});
    printf(str);
}
// STAGE_WIDTH/HEIGHT 크기의 맵을 그린다.
// stageInfo는 x 한 칸을 1의 크기로, rendering 시에는 한 칸을 2의 크기로 만든다.
void initStage() {
    for (int i = 0; i < STAGE_HEIGHT+1; i++) {
        drawAt(0, i, "│");
        drawAt(1+2*STAGE_WIDTH, i, "│");
    }
    drawAt(0, STAGE_HEIGHT+1, "└");
    // block 개수 * 2
    for (int i = 1; i <= 2*STAGE_WIDTH; i++)
        {   drawAt(i, STAGE_HEIGHT-2, "🟥");
            drawAt(i, STAGE_HEIGHT+1, "─");}
    
    printf("┘");
}
