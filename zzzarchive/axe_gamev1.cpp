#include "raylib.h"

int main() {
 

    int width = 800;
    int height = 500;
    InitWindow(width,height,"Xris's amazing game!");
    //string title = "Hi Xris!"; 

    // cicle coordinates
    int circle_x{200};
    int circle_y{200};
    //radius
    float circle_radius{50};
    //circle edges
    int l_circle_x{circle_x - circle_radius}, r_circle_x{circle_x + circle_radius}, u_circle_y{circle_y - circle_radius}, b_circle_y{circle_y + circle_radius};

    //axe coordinates
    int axe_x{400}, axe_y{0};
    int direction{4};
    int axe_length = 50;
    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y}, b_axe_y{axe_y + axe_length};
    
    
    SetTargetFPS(60);
    Texture2D texture = LoadTexture("x1.png");

    //game loop
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //Game Logic Begins    
        DrawTexture(texture, width/2 - texture.width/2, height/2 - texture.height/2, WHITE);
        DrawCircle(circle_x,circle_y,circle_radius,BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
        

        //move the ax
        axe_y += direction;
            if(axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if(IsKeyDown(KEY_D) && circle_x < width - circle_radius){
                circle_x += 4;
            }

            if(IsKeyDown(KEY_A) && circle_x > 0 + circle_radius){
                circle_x -= 4;
            }    

            if(IsKeyDown(KEY_W) && circle_y > 0 + circle_radius){
                circle_y -= 4;
            }

            if(IsKeyDown(KEY_S) && circle_y < height - circle_radius){
                circle_y += 4;
            }
            DrawText("Hello Xris!!!", 270, 200, 20, DARKGRAY);
        //Game Logic Ends
        EndDrawing();
    }

    CloseWindow();
    return 0;
}