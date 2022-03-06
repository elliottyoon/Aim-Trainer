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

## To Do (later):
* Make sure crosshair is centered
* getter/setters for everything
