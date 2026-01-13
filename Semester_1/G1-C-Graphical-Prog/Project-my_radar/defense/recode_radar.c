#include <stdio.h>
#include <SFML/Graphics.h>

int my_collision(sfSprite *sprite1, sfSprite *sprite2)
{
    sfFloatRect position1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect position2 = sfSprite_getGlobalBounds(sprite2);

    if (sfFloatRect_intersects(&position1, &position2, NULL) == sfTrue) {
        return 1;
    } else {
        return 0;
    }
    return 84;
}

int main(void)
{
    sfSprite *sprite1 = sfSprite_create();
    sfSprite *sprite2 = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("image.jpg", NULL);

    if (sprite1 == NULL || sprite2 == NULL || texture == NULL) {
	printf("error\n");
	return 84;
    }
    
    sfSprite_setTexture(sprite1, texture, sfTrue);
    sfSprite_setTexture(sprite2, texture, sfTrue);

    sfSprite_setPosition(sprite1, (sfVector2f){0.f, 0.f});
    sfSprite_setPosition(sprite2, (sfVector2f){-10.f, -20.f});
    printf("test1: %d (expected 1)\n", my_collision(sprite1, sprite2));

    sfSprite_setPosition(sprite1, (sfVector2f){-50.f, -200.f});
    sfSprite_setPosition(sprite2, (sfVector2f){-40.f, 400.f});
    printf("test1: %d (expected 0)\n", my_collision(sprite1, sprite2));

    sfSprite_setPosition(sprite1, (sfVector2f){300.f, 400.f});
    sfSprite_setPosition(sprite2, (sfVector2f){150.f, 230.f});
    printf("test1: %d (expected 1)\n", my_collision(sprite1, sprite2));

    sfSprite_destroy(sprite1);
    sfSprite_destroy(sprite2);
    sfTexture_destroy(texture);
    return 0;
}
