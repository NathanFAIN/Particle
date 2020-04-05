/*
** EPITECH PROJECT, 2020
** particle
** File description:
** particle
*/

//----------------------------------------------------------------------------
// Voici le fichier que ou tu devras coder.
// Il y a 7 fonctions à faire, bonne chance!
// (N'hésites pas à poser des questions si quelque chose n'est pas clair)
//----------------------------------------------------------------------------

#include "particle.h"

/*
Initialises particle_environment à l'aide des autres arguments.
Composantes à initialiser:
- angle_min
- angle_max
- gravity
- alpha
- speed (par défaut égale à SPEED)
- circle_shape : sfCircleShape_create()
- clock : sfClock_create()
*/
void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    (void)particle_environment;
    (void)angle;
    (void)gravity;
    (void)alpha;
}

/*
Initialises la particule à l'aide des paramètres présent dans 
la variale particle_environment et pos.
Composantes à initialiser:
- pos
- color
- vel
- pos
- living
- radius
*/
void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    (void)particle_environment;
    (void)particule;
    (void)pos;
    /*
    Petit aide pour le calcul de vel:

    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    */
}

/*
Affiches un cercle (ta particule) à la bonne taille, couleur et position.
Pour cela, tu peux te servire du sfCircleShape.
*/
void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape)
{
    (void)window;
    (void)particule;
    (void)circle_shape;
}

/*
Affiches toutes les particules en vie dans le tableau.
Pour cela, tu peux te servire de la fonction display_particle().
*/
void display_all_particles(sfRenderWindow *window, \
const particle_t *particule, sfCircleShape *circle_shape)
{
    (void)window;
    (void)particule;
    (void)circle_shape;
}

/*
Mets à jour la particule à l'aide des caractéristiques de particle_environment.
(Le faire si uniquement la particule est en vie: particule->living == true)
Composantes à mettre à jour:
- color (le alpha)
- vel
- pos
- living (parfois)
*/
void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule)
{
    (void)particle_environment;
    (void)particule;
}

/*
Mets à jour toutes les particules en vie dans le tableau.
Pour cela, tu peux te servire de la fonction update_particle().
N'oublies pas de te servire de la sfClock présent dans particle_environment
pour ne pas mettre à jour à chaque tour de boucle.
(sinon n'animation risque d'etre trop rapide...)
*/
void update_all_particles(const particle_environment_t *particle_environment, \
particle_t *particule)
{
    (void)particle_environment;
    (void)particule;
}

/*
Initialises particle_num particules à la position pos.
(Parcours le tableau de particule et initialises les particules
qui ne sont pas déjà utilisées: particule[index].living == false).
Pour cela, tu pourras faire appel à la fonction init_particule().
*/
void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    (void)particle_environment;
    (void)particule;
    (void)particle_num;
    (void)pos;
}