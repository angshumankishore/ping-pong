#include "raylib.h"

struct Ball{
    float positionX;
    float positionY;
    float speedX;
    float speedY;
    float radius; 

    void Draw(){
        DrawCircle(positionX, positionY, radius, WHITE); 
    }
}; 

struct Paddle{
    float positionX;
    float positionY;
    float width;
    float height; 
    float speed; 
    Rectangle GetRect(){
        return Rectangle{positionX - width/2, positionY - height/2, 10, 100}; 
    }
    void Draw(){
        DrawRectangle(positionX - width/2, positionY - height/2, 10, 100, WHITE);
    }
};
const char *winnertext = nullptr; 

int main() {

    //creating a window 
    InitWindow(800, 600, "raylib test");
    SetWindowState(FLAG_VSYNC_HINT); 
    Ball ball; 
    ball.positionX = GetScreenWidth()/2;
    ball.positionY = GetScreenHeight()/2;
    ball.speedX = 100;
    ball.speedY = 300;
    ball.radius = 5;
    float ballPositionX = GetScreenWidth()/2;
    float ballPositionY = GetScreenHeight()/2;
    float ballSpeedX = 100; 
    float ballSpeedY = 300; 

    Paddle leftPaddle;
    leftPaddle.positionX = 50;
    leftPaddle.positionY = (GetScreenHeight()/2);
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 300;

    Paddle rightPaddle;
    rightPaddle.positionX = GetScreenWidth() - 50; 
    rightPaddle.positionY = GetScreenHeight()/2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 300;



    //creating a game window loop 
    while(!WindowShouldClose()){
        //start drawing 
        BeginDrawing(); 

        ClearBackground(BLACK); 

        
        ball.positionX += ball.speedX*GetFrameTime();
        ball.positionY += ball.speedY*GetFrameTime();
        

        if(ball.positionY >= GetScreenHeight()){
            ball.positionY = GetScreenHeight();
            ball.speedY *= -1; 
        }
        if(ball.positionY <= 0){
            ball.positionY = 0; 
            ball.speedY *= -1;
        }
        //move the paddles 
        if(IsKeyDown(KEY_W)){
            
            leftPaddle.positionY -= leftPaddle.speed*GetFrameTime();
        }
        if(IsKeyDown(KEY_S)){
            leftPaddle.positionY += leftPaddle.speed*GetFrameTime();
        }
        if(IsKeyDown(KEY_UP)){
            rightPaddle.positionY -= rightPaddle.speed*GetFrameTime();
        }
        if(IsKeyDown(KEY_DOWN)){
            rightPaddle.positionY += rightPaddle.speed*GetFrameTime();
        }
        if(CheckCollisionCircleRec(Vector2{ball.positionX,ball.positionY},ball.radius,rightPaddle.GetRect())){
            if(ball.speedX > 0){
                ball.speedX *= -1.1f; 
                ball.speedY += (ball.positionY - rightPaddle.positionY)/(rightPaddle.height/2)*(-ball.speedX);
            }
            
        }
        if(CheckCollisionCircleRec(Vector2{ball.positionX,ball.positionY},ball.radius,leftPaddle.GetRect())){
            if(ball.speedX < 0){
                ball.speedX *= -1.1f; 
                ball.speedY += (ball.positionY - leftPaddle.positionY)/(leftPaddle.height/2)*(ball.speedX);
            }
            
        }
        if(ball.positionX < 0){
            winnertext = "Right Player Wins!";
        }
        if(ball.positionX > GetScreenWidth()){
            winnertext = "Left Player Wins!";
        }

        //drawing a circle 
        ball.Draw();
        leftPaddle.Draw();
        rightPaddle.Draw();

        if(winnertext != nullptr){
            DrawText(winnertext, GetScreenWidth()/2 - MeasureText(winnertext, 20)/2, GetScreenHeight()/2 - 10, 20, WHITE);
        }
        if(winnertext && IsKeyPressed(KEY_SPACE)){
            winnertext = nullptr; 
            ball.positionX = GetScreenWidth()/2;
            ball.positionY = GetScreenHeight()/2;
            ball.speedX = 100; 
            ball.speedY = 300; 
        }
        

        DrawFPS(10,10); 

        EndDrawing(); //handles events 

    }

    //closing a window 

    CloseWindow(); 
}