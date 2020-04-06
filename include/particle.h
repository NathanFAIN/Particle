/*
** EPITECH PROJECT, 2020
** particle
** File description:
** particle
*/

//----------------------------------------------------------------------------
// Pas desoin de toucher au code présent dans particule.h.
// Mais rien ne t'empeche de le regarder!
//----------------------------------------------------------------------------

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>           // cos() & sin()
#include <stdlib.h>         // exit()
#include <stdbool.h>        // bool
#include <string.h>         // memeset()

#define WINDOW_HEIGHT (1080)
#define WINDOW_WIDTH (1920)
#define WINDOW_NAME "~"

#define PARICULE_ANGLE_MIN (0)
#define PARICULE_ANGLE_MAX (6.2832f)
#define GRAVITY_X (1.0f * 0)
#define GRAVITY_Y (1.0f * 0)
#define ALPHA (1)

#define PARICULE_MAX (10000)
#define SPEED (1.0f)

typedef struct particle_environment_s particle_environment_t;
typedef struct particle_s particle_t;
typedef struct screen_s screen_t;

struct particle_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    bool living;
};

struct particle_environment_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfCircleShape *circle_shape;
};

struct screen_s {
    sfRenderWindow *window;
    sfEvent event;
    sfKeyCode key;
    particle_t particle[PARICULE_MAX];
    particle_environment_t particle_environment;
};

// Initialise l'environnement des particules (vitesse, vélocité, gravité, ...)
void init_particle_environment(particle_environment_t *particle_environment, const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);

// Initialise une particule
void init_particule(const particle_environment_t *particle_environment, particle_t *particule, const sfVector2f pos);

// Affiche une particule
void display_particle(sfRenderWindow *window, const particle_t *particule, sfCircleShape *circle_shape);

// Met à jour une particule
void update_particle(const particle_environment_t *particle_environment, particle_t *particule);

// Rend particle_num particules actives
void add_particle(const particle_environment_t *particle_environment, particle_t *particule, const size_t particle_num, const sfVector2f pos);

#endif
