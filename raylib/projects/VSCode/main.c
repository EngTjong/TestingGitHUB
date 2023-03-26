#include "raylib.h"
#include <math.h>
#include <time.h>

#define CLOCK_RADIUS 200
#define CLOCK_CENTER_X 225
#define CLOCK_CENTER_Y 225

int main(void)
{
    // Initialize window and clock face
    InitWindow(450, 450, "Analog Clock");
    SetTargetFPS(60);
    
    // Main loop
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_ESCAPE))
        {
            break;
        }
        // Clear the screen and draw the clock face
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(CLOCK_CENTER_X, CLOCK_CENTER_Y, CLOCK_RADIUS, BROWN);
        DrawCircle(CLOCK_CENTER_X, CLOCK_CENTER_Y, 10, BLACK);
        
        // Calculate the position of the hour, minute, and second hands
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        int hour = tm_info->tm_hour % 12;
        int minute = tm_info->tm_min;
        int second = tm_info->tm_sec;
        float hour_angle = (((hour) * 30 + (minute) / 2.0)-90) * PI / 180.0;
        float minute_angle = ((minute) * 6-90) * PI / 180.0;
        float second_angle = ((second) * 6-90) * PI / 180.0;
        Vector2 hour_pos = (Vector2) {
            CLOCK_CENTER_X + cos(hour_angle) * CLOCK_RADIUS * 0.5,
            CLOCK_CENTER_Y + sin(hour_angle) * CLOCK_RADIUS * 0.5
        };
        Vector2 minute_pos = (Vector2) {
            CLOCK_CENTER_X + cos(minute_angle) * CLOCK_RADIUS * 0.7,
            CLOCK_CENTER_Y + sin(minute_angle) * CLOCK_RADIUS * 0.7
        };
        Vector2 second_pos = (Vector2) {
            CLOCK_CENTER_X + cos(second_angle) * CLOCK_RADIUS * 0.9,
            CLOCK_CENTER_Y + sin(second_angle) * CLOCK_RADIUS * 0.9
        };
        
        // Draw the hour, minute, and second hands
        DrawLineEx((Vector2) {CLOCK_CENTER_X, CLOCK_CENTER_Y}, hour_pos, 10, BLACK);
        DrawLineEx((Vector2) {CLOCK_CENTER_X, CLOCK_CENTER_Y}, minute_pos, 5, BLACK);
        DrawLineEx((Vector2) {CLOCK_CENTER_X, CLOCK_CENTER_Y}, second_pos, 2, RED);
        float second_angle_rec=second_angle*RAD2DEG;
        Rectangle rec = {CLOCK_CENTER_X, CLOCK_CENTER_Y,20, 20};
        DrawRectanglePro(rec,(Vector2){10,10},second_angle_rec, RED);
        
        EndDrawing();
    }
    
    // Close window and exit
    CloseWindow();
    return 0;
}
