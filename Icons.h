//
// Created by insane on 12.06.19.
//

#ifndef RAYCONS_ICONS_H
#define RAYCONS_ICONS_H

#endif //RAYCONS_ICONS_H

#include <raylib.h>


class Icons {
public:
    static void gpsFixed(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        Icons::gpsUnFixed(x, y, sizeX, sizeY);
        DrawCircle(xc, yc, sizeX / 4, GREEN);
    }

    static void gpsUnFixed(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawCircle(xc, yc, sizeX - 4, GREEN);
        DrawLineEx(Vector2{xc, yc - sizeX}, Vector2{xc, yc + sizeY}, 1, GREEN);
        DrawLineEx(Vector2{xc - sizeX, yc}, Vector2{xc + sizeX, yc}, 1, GREEN);
        // DrawCircle(xc, yc, sizeX - sizeX / 4 - 0.2, BLACK); // dotted
        DrawCircle(xc, yc, sizeX - 5, BLACK);
    }

    static void bluetoothEnabled(int x, int y, int sizeX, int sizeY){
        int xs = sizeX / 4;
        int ys = sizeY / 4;
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawCircle(xc, yc, sizeX - 2, GREEN);
        DrawCircle(xc, yc, sizeX - 3, BLACK);
        DrawLineEx(Vector2{xc - xs, yc - ys}, Vector2{xc + xs, yc + ys}, 1, GREEN);
        DrawLineEx(Vector2{xc + xs, yc + ys}, Vector2{xc, yc + ys * 2}, 1, GREEN);
        DrawLineEx(Vector2{xc, yc + ys * 2}, Vector2{xc, yc - ys * 2}, 1, GREEN);
        DrawLineEx(Vector2{xc, yc - ys * 2}, Vector2{xc + xs, yc - ys}, 1, GREEN);
        DrawLineEx(Vector2{xc + xs, yc - ys}, Vector2{xc - xs, yc + ys}, 1, GREEN);
    }

    static void bluetoothDisabled(int x, int y, int sizeX, int sizeY){
        bluetoothEnabled(x, y, sizeX, sizeY);
        DrawLineEx(Vector2{x, y}, Vector2{x + sizeX, y + sizeY}, 2, GREEN);
        // DrawLineEx(Vector2{x + sizeX, y}, Vector2{x, y + sizeY}, 2, GREEN);
    }

    static void wifiEnabled(int x, int y, int sizeX, int sizeY){ // todo strength? for loop drawcirclelines
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawCircleLines(xc, yc, sizeX, GREEN);
        DrawCircleLines(xc, yc, sizeX / 1.2, GREEN);
        DrawCircleLines(xc, yc, sizeX / 1.4, GREEN);
        DrawCircleLines(xc, yc, sizeX / 1.6, GREEN);
        DrawCircleLines(xc, yc, sizeX / 2, GREEN);
        DrawRectangle(x - sizeX + sizeX / 2, yc, sizeX * 2 + sizeX / 2, sizeY / 2 + sizeX / 2, BLACK);
        DrawTriangle((Vector2){x + sizeX / 1.4, y - sizeY / 4},
                     (Vector2){x + sizeX, yc},
                     (Vector2){xc, yc}, VIOLET);
        DrawTriangle((Vector2){x - sizeX / 1.4, y - sizeY / 4},
                     (Vector2){x - sizeX / 1.4, yc},
                     (Vector2){xc, yc}, BLACK);
        //DrawTriangle(Vector2{xc, yc}, Vector2{xc + sizeX, yc}, Vector2{x + sizeX, y - sizeX / 2}, GREEN);
        DrawCircle(xc, yc, sizeX / 4, GREEN);

        /*
        DrawCircleLines(xc, yc, sizeX, GREEN);
        DrawCircleLines(xc, yc, sizeX / 1.4, GREEN);
        DrawCircleLines(xc, yc, sizeX / 1.8, GREEN);
        DrawCircleLines(xc, yc, sizeX / 2.6, GREEN);
        DrawCircleLines(xc, yc, sizeX / 3.2, GREEN);
        */
    }

    static void wifiDisabled(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        wifiEnabled(x, y, sizeX, sizeY);
    }

    static void play(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawLineEx(Vector2{x, y}, Vector2{x + sizeX, yc}, sizeX / 4, GREEN);
        DrawLineEx(Vector2{x + sizeX, yc}, Vector2{x, y + sizeY}, sizeX / 4, GREEN);
        DrawLineEx(Vector2{x, y + sizeY}, Vector2{x, y}, sizeX / 4, GREEN);
    }

    static void pause(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawLineEx(Vector2{x, y}, Vector2{x, y + sizeY}, sizeX / 4, GREEN);
        DrawLineEx(Vector2{x + sizeX, y}, Vector2{x + sizeX, y + sizeY}, sizeX / 4, GREEN);
    }

    static void album(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawCircle(xc, yc, sizeX, GREEN);
        DrawCircle(xc, yc, sizeX / 2, BLACK);
        DrawCircle(xc, yc, sizeX / 5, GREEN);
    }

    static void home(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawRectangle(x, yc, sizeX, sizeY / 2, GREEN);
        DrawTriangle(Vector2{xc, y}, Vector2{x, yc}, Vector2{x + sizeX, yc}, GREEN);
        DrawRectangle(xc - sizeX / 4, yc + sizeY / 2 - sizeY / 4, sizeX / 4, sizeY / 4, BLACK);
        DrawRectangle(x, yc, sizeX / 8, sizeY / 2, BLACK);
        DrawRectangle(x + sizeX - sizeX / 8, yc, sizeX / 8, sizeY / 2, BLACK);
    }

    static void navigation(int x, int y, int sizeX, int sizeY){
        int xc = x + sizeX / 2;
        int yc = y + sizeY / 2;
        DrawTriangle(Vector2{xc, y},
                     Vector2{xc - sizeX / 2, y + sizeY},
                     Vector2{xc + sizeX / 2, y + sizeY}, GREEN);
        DrawTriangle(Vector2{xc, y + sizeY / 1.4},
                     Vector2{xc - sizeX / 2, y + sizeY},
                     Vector2{xc + sizeX / 2, y + sizeY}, BLACK);
    }
};