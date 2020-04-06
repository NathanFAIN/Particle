/*
** EPITECH PROJECT, 2020
** particle
** File description:
** main
*/

//----------------------------------------------------------------------------
// Pas desoin de toucher au code présent dans main.c.
// Mais rien ne t'empeche de le regarder!
//----------------------------------------------------------------------------

#include "particle.h"

//--------------Creation-de-la-fenettre--------------
sfRenderWindow *create_window(const size_t width, \
const size_t height, const char *window_name)
{
    sfRenderWindow *new_window;
    sfVideoMode video_mode;

    video_mode.bitsPerPixel = 32;
    video_mode.width = width;
    video_mode.height = height;
    new_window = sfRenderWindow_create(video_mode, window_name, sfClose, NULL);
    if (!new_window)
        exit(84);
    sfRenderWindow_setPosition(new_window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(new_window, 60);
    return (new_window);
}

//--------------Récupération-des-évènements--------------
void manage_event_window(sfRenderWindow *window, sfKeyCode *key)
{
    sfEvent event;

    *key = sfKeyUnknown;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        } else if (event.type == sfEvtKeyPressed) {
            *key = event.key.code;
        }
    }
}

//--------------Gestion-des-évènements-(clavier)--------------
void manage_key_window(screen_t *screen, const sfKeyCode *key)
{
    sfVector2i pos;

    if (*key == sfKeySpace) {

        // -------------------------------------------------------------------
        // On fait apparaitre 20 particules à la position du curseur:
        pos = sfMouse_getPositionRenderWindow(screen->window);
        add_particle(&screen->particle_environment, screen->particle, \
        // -------------------------------------------------------------------

        20, (sfVector2f){pos.x, pos.y});
    } else if (*key == sfKeyEscape) {
        sfRenderWindow_close(screen->window);
    }
}

//--------------Boucle-d'affichage---------------
void display_window(screen_t *screen)
{
    while (sfRenderWindow_isOpen(screen->window)) {
        manage_event_window(screen->window, &screen->key);
        manage_key_window(screen, &screen->key);

        // -------------------------------------------------------------------
        // On met à jour tout les particules:
        for (size_t index = 0; index != PARICULE_MAX; index++)
            update_particle(&screen->particle_environment, \
            &screen->particle[index]);
        // -------------------------------------------------------------------

        sfRenderWindow_clear(screen->window, sfBlack);

        // -------------------------------------------------------------------
        // On affiche tout les particules:
        for (size_t index = 0; index != PARICULE_MAX; index++)
            display_particle(screen->window, &screen->particle[index], \
            screen->particle_environment.circle_shape);
        // -------------------------------------------------------------------

        sfRenderWindow_display(screen->window);
    }
}

int main(void)
{
    screen_t screen;

    memset(&screen, 0, sizeof(screen));
    screen.window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    init_particle_environment(&screen.particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);

    display_window(&screen);
    sfClock_destroy(screen.particle_environment.clock);
    sfCircleShape_destroy(screen.particle_environment.circle_shape);
    sfRenderWindow_destroy(screen.window);
    return (0);
}