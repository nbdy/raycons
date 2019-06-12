#include <iostream>
#include <raylib.h>
#include "Icons.h"


int main(int argc, char** argv) {
    InitWindow(800, 600, "carpi");
    SetTargetFPS(30);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        // bt
        Icons::bluetoothEnabled(260, 20, 32, 32);
        Icons::bluetoothDisabled(340, 20, 32, 32);
        Icons::bluetoothEnabled(20, 20, 16, 16);
        Icons::bluetoothDisabled(80, 20, 16, 16);
        Icons::bluetoothEnabled(140, 20, 8, 8);
        Icons::bluetoothDisabled(200, 20, 8, 8);
        // gps
        Icons::gpsUnFixed(260, 100, 32, 32);
        Icons::gpsFixed(340, 100, 32, 32);
        Icons::gpsUnFixed(20, 100, 16, 16);
        Icons::gpsFixed(80, 100, 16, 16);
        Icons::gpsUnFixed(140, 100, 8, 8);
        Icons::gpsFixed(200, 100, 8, 8);
        //
        DrawFPS(8, 576);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}