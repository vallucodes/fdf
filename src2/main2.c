// #include "MLX42/MLX42.h"
// #include <stdlib.h>
// #include <string.h>

// // Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
// #define BPP sizeof(int32_t)

// // void draw_line(int32_t* pixels, int width, int x1, int y1, int x2, int y2, int color)
// // {
// //     int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
// //     int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
// //     int err = dx + dy, e2;

// //     while (1)
// //     {
// //         pixels[y1 * width + x1] = color; // Set pixel color
// //         if (x1 == x2 && y1 == y2) break;
// //         e2 = 2 * err;
// //         if (e2 >= dy) { err += dy; x1 += sx; }
// //         if (e2 <= dx) { err += dx; y1 += sy; }
// //     }
// // }

// void draw_circle(int32_t* pixels, uint32_t width, uint32_t height, int cx, int cy, unsigned int radius, unsigned int radius2, uint32_t color)
// {
//     for (uint32_t y = 0; y < height; y++) // Use uint32_t for y
//     {
//         for (uint32_t x = 0; x < width; x++) // Use uint32_t for x
//         {
//             // Check if the pixel is inside the circle
//             if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= radius * radius)
//             {
//                 if ((x - cx) * (x - cx) + (y - cy) * (y - cy) >= radius2 * radius2)
//                     pixels[y * width + x] = color; // Set the pixel color
//             }
//         }
//     }
// }

// int32_t	main(void)
// {
//     // Init mlx with a canvas size of 256x256 and the ability to resize the window.
//     mlx_t* mlx = mlx_init(1000, 1000, "MLX42", true);

//     if (!mlx) exit(EXIT_FAILURE);


//     // Create a 128x128 image.
//     mlx_image_t* img = mlx_new_image(mlx, 1500, 1500);

//     // int32_t* pixels = (int32_t*)img->pixels; // Cast pixels to int32_t* for RGBA

//     // draw_line(pixels, img->width, 10, 10, 600, 500, 0xFF0000FF);
//     draw_circle((int32_t*)img->pixels, img->width, img->height, 300, 300, 300, 250, 0xFF6A5ACD);
//     // memset(img->pixels, 255, img->width * img->height * BPP);

//     // Draw the image at coordinate (0, 0).
//     mlx_image_to_window(mlx, img, 100, 200);

//     // Run the main loop and terminate on quit.
//     mlx_loop(mlx);
//     mlx_terminate(mlx);

//     return (EXIT_SUCCESS);
// }
