#include <iostream>
#include <raylib.h>
#include <vector>
#include <fstream>

typedef std::pair<Vector2, Vector2> line;
typedef std::vector<line> lines;

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


class RayconReader {
public:
    static line parseLine(const std::string& line){

    }

    static lines parseFile(const std::string& infile){
        lines r;
        std::ifstream i(infile);
        std::string l;
        while(std::getline(i, l)) r.emplace_back(RayconReader::parseLine(l));
        return r;
    }
};


class RayconWriter {
public:
    static void write(const std::string& ofile, lines l){
        std::ofstream o(ofile);
        for(auto i : l){
            std::string ol = std::to_string(i.first.x) + "," + std::to_string(i.first.y) + ";" + std::to_string(i.second.x) + "," + std::to_string(i.second.y) + "\n";
            std::cout << ol << std::endl;
            o.write(ol.c_str(), ol.size());
        }
    }
};

int draw(){
    lines clickedPositions;
    bool clickedOnce = false;
    Vector2 lastPosition;

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            Vector2 mP = GetMousePosition();
            if(clickedOnce){
                clickedPositions.emplace_back(line{lastPosition, mP});
                clickedOnce = false;
            } else {
                lastPosition = mP;
                clickedOnce = true;
            }
        }
        if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){
            clickedOnce = false;
        }
        for(auto i : clickedPositions){
            DrawLineEx(i.first, i.second, 2, GREEN);
        }
        /*
        Icons::gpsFixed(420, 420, 16, 16);
        Icons::gpsUnFixed(360, 420, 16, 16);
        Icons::bluetoothEnabled(300, 420, 16, 16);
        */
        DrawFPS(8, 576);
        EndDrawing();
    }
    RayconWriter::write("test.txt", clickedPositions);
}


void read(const std::string& infile){
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        DrawFPS(8, 576);
        EndDrawing();
    }
}

void readFolder(const std::string& folder){

}


int main(int argc, char** argv) {
    InitWindow(800, 600, "carpi");
    SetTargetFPS(30);
    if(argc > 1){
        if(std::string(argv[1]) == "-d") draw();
        else if(std::string(argv[1]) == "-p") read(std::string(argv[2]));
        else if(std::string(argv[1]) == "-f") readFolder(std::string(argv[2]));
    } else {
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
    }
    CloseWindow();
    return 0;
}