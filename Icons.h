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

    static void play(){

    }

    static void pause(){

    }
};