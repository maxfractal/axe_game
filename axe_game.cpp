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
    float circle_radius{25};
    int l_circle_x{circle_x - circle_radius}, r_circle_x{circle_x + circle_radius}, u_circle_y{circle_y - circle_radius}, b_circle_y{circle_y + circle_radius};

    //axe coordinates
    int axe_x{400}, axe_y{0};
    //length
    int axe_length = 50;
    int l_axe_x{axe_x}, r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y}, b_axe_y{axe_y + axe_length};
    int direction = 4;
    bool collision_with_axe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);
    
    SetTargetFPS(60);
    Texture2D texture = LoadTexture("x1.png");

    //game loop
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        if (collision_with_axe) {
            DrawText("Game Over!", 290, 200, 62, RED);
        } 
        else 
        {
            //Game Logic Begins

            //update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            //upate collision_with_axe
            collision_with_axe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

            DrawText(TextFormat("Circle X: %i", circle_x), 40, 10, 20, RED);
            DrawText(TextFormat("Circle Y: %i", circle_y), 40, 30, 20, RED);

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
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}