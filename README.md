# Notes

Components:
* Model
  * Represent the intial window size
  * Balls should only spawn within the model and not outside
  the window dimensions
* View
  * Represents the perspective of the player as they move their
    crosshair around
* Ball
  * Spawn in the model
* Crosshair
  * Any crosshair movement should shift every **view** of the
    ball according to the displacement vector from the last mouse
    position to the current mouse movement

## To Do:
1. ~~Monday:~~
   * ~~make crosshair move with mouse (but stay centered)~~
   * ~~if crosshair clicks on ball, ball disappears~~
     * ~~sound plays~~
3. Tuesday:
   * ~~Fix crosshair on ball detection (from Monday)~~
   * ~~Create crosshair class~~
   * ~~Display score~~
   * ~~Display time elapsed~~
   * Add menu box
     * Number of balls on screen at a time
* **Miscellaneous**
  * Find better audio for hit/miss sound

[//]: # (## Specifications)
1. ~~Balls will randomly pop up on the screen~~
2. Number of balls on a screen at a given time can be modified by user
3. ~~Balls will disappear when clicked on by cursor~~
4. ~~Balls will make a sound when clicked on by cursor~~
5. ~~Number of balls clicked will be displayed on screen~~
6. ~~Time elapsed since session start will be displayed on screen~~
7. ~~Cursor will be fixed in center of screen; movement will shift perspective~~
8. User will be able to select among different modes: (yes)
9. Mode 1: ball will pop up on the screen and disappear after a short amount of t?me if not clicked by user (yes)
10. Mode 2: balls will pop up on the screen and if too many balls on screen, user loses. (not yet)
