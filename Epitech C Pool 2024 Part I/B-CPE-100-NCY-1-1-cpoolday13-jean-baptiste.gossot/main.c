/*
** EPITECH PROJECT, 2024
** main 
** File description:
** file for day 13 csfml
*/
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdlib.h>

int main(void)
{
    sfVideoMode mode;
    sfEvent event;
    sfUint8 *pixels;
    
    mode.width = 800;
    mode.height = 600;
    mode.bitsPerPixel = 32;
    pixels = malloc(mode.width * mode.height * mode.bitsPerPixel / 8);

    pixels[0] = 234;
    pixels[1] = 56;
    pixels[2] = 122;
    pixels[3] = 255;
    display_framebuffer(pixels, mode.width, mode.height);
    
    sfRenderWindow *window = sfRenderWindow_create(mode, "Marvin je t'aime", sfDefaultStyle, NULL);
    while(sfRenderWindow_isOpen(window)) {
        while(sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
    }
    return 0;
}
