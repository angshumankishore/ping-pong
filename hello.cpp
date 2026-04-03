#include "raylib.h"

int main() {

    //creating a window 
    InitWindow(800, 600, "raylib test");
    SetWindowState(FLAG_VSYNC_HINT); 
    float ballPositionX = GetScreenWidth()/2;
    float ballPositionY = GetScreenHeight()/2;
    float ballSpeedX = 300; 
    float ballSpeedY = 300; 


    //creating a game window loop 
    while(!WindowShouldClose()){
        //start drawing 
        BeginDrawing(); 

        ClearBackground(BLACK); 
        
        ballPositionX += ballSpeedX*GetFrameTime();
        ballPositionY += ballSpeedY*GetFrameTime();

        if(ballPositionY >= GetScreenHeight()){
            ballPositionY = GetScreenHeight();
            ballSpeedY *= -1; 
        }
        if(ballPositionY <= 0){
            ballPositionY = 0; 
            ballSpeedY *= -1;
        }
        //drawing a circle 
        DrawCircle(ballPositionX, ballPositionY,5,WHITE); 
        DrawRectangle(30,(GetScreenWidth()/2)-30,10,100,WHITE);
        DrawRectangle(GetScreenWidth()-30-10,(GetScreenWidth()/2)-30,10,100,WHITE);

        DrawFPS(10,10); 

        EndDrawing(); //handles events 

    }

    //closing a window 

    CloseWindow(); 
}