/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:11:13 by tbornema          #+#    #+#             */
/*   Updated: 2023/12/14 13:25:17 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdlib.h> // For malloc, free
#include <unistd.h> // For write
#include "../libft/libft.h"
#include <math.h> // For mathematical operations
#include <X11/X.h> // X11 core library
#include <X11/keysym.h> // Key symbols
#include "../minilibx-linux/mlx.h" // MinilibX library


// Constants
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 2000

// EVENTS
#define BASE_MOVE 0.0001
#define SCALE 0.1


// Define colors
#define NUMCOLORS 23
#define BLACK 		0x000000
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define DEEP_PURPLE		0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red
#define SUNSET_ORANGE   0xFF5733  // A warm, deep orange
#define GOLDEN_YELLOW   0xFFD700  // A bright, shiny gold
#define EMERALD_GREEN   0x50C878  // A vivid, green gemstone color
#define SKY_BLUE        0x87CEEB  // A light, airy blue
#define ROYAL_PURPLE    0x7851A9  // A deep, regal purple
#define CHERRY_BLOSSOM  0xFFB7C5  // A soft, delicate pink
#define TURQUOISE       0x40E0D0  // A medium turquoise blue-green
#define MIDNIGHT_BLUE   0x191970  // A dark, deep blue
#define AMBER           0xFFBF00  // A warm yellow-orange, like the gemstone
#define SLATE_GRAY      0x708090  // A gray with a hint of blue

// Complex number structure
typedef struct s_complex
{
    double real; // Real part
    double unreal; // Imaginary part
} t_complex;

// Image structure
typedef struct s_img
{
    void *img_ptr; // Pointer to the image
    char *addr; // Address of the image
    int bpp; // Bits per pixel
    int line_length; // Length of a line in the image
    int endian; // Endianess of the image
} t_img;

// Fractol structure
typedef struct s_fractol
{
    void *mlx; // Pointer to the mlx instance
    void *window; // Pointer to the window
	double zoom; // Zoom function with mousewheel
	double	julia_x;
	double	julia_y;
	double	mandel_x;
	double	mandel_y;
	char *name;
	t_complex center;
    t_img imgage; // Image structure
    // ... other fractal-specific parameters ...
} t_fractol;

// Function prototypes
void	open_window(t_fractol *fractol);
void ft_render_fractal(t_fractol *fractal);
t_complex	ft_pixel_to_complexnumber(int x, int y, t_fractol *fractol);
int	ft_get_color(int depth);
int	ft_mandelbrot(t_complex c, int max_iter);
int ft_julia(t_complex z, t_complex c, int max_iter);
int	ft_mouse_hook(int button, int x, int y, t_fractol *fractol);
int ft_key_hook(int keycode, t_fractol *fractol);
// ... other function prototypes ...

#endif
