# **WARNING: This may potentially trigger seizures for people with photosensitive epilepsy. Viewer discretion is advised.**
_The running executable, not this readme._
<br>

## Fractol
A fractol visualization project as part of the core curriculum at 42. It uses multithreading and a custom OpenGL library to calculate and render images.
The current source will compile on MacOS El Capitan, although a zip of the sources for compiling on X11 systems is included.
<br>
[X](https://media.giphy.com/media/26Ff2r1ns9qtwXWeI/giphy.gif) 
[X](https://media.giphy.com/media/3ohjV3RU7T0U61Jio0/giphy.gif) 
[X](https://media.giphy.com/media/xT1Ra32KJxhOTwxeE0/giphy.gif) 
[X](https://media.giphy.com/media/xT1R9QpHxsqghnItUc/giphy.gif)
### Fractals included:

##### Julia
![Julia Set Fractal](https://raw.githubusercontent.com/izcet/fractol/master/pics/julia.png)
<br>

##### Mandelbrot
![Mandelbrot Set Fractal](https://raw.githubusercontent.com/izcet/fractol/master/pics/mandelbrot.png)
<br>

##### Mandelcube
![Mandelbrot Cubed Set Fractal](https://raw.githubusercontent.com/izcet/fractol/master/pics/mandelcube.png)
<br>

##### Juliacube
![Julia Cubed Set Fractal](https://raw.githubusercontent.com/izcet/fractol/master/pics/juliacube.png)
<br>

##### Sierpinski Triangle
![Sierpinski Triangle Fractal](https://raw.githubusercontent.com/izcet/fractol/master/pics/sierpinski.png)
<br>

##### Bad Julia
_Not a unique fractal, but an error in the base Julia set that still mutates during zoom and translation, when it normally shouldn't. I kept it in the project as a bonus because it looks hella cool._
![Julia Set Fractal](https://raw.githubusercontent.com/izcet/fractol/master/pics/badjulia.png)
<br>

### Color Palettes included:
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/izzetburn.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/simicsynergy.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/waroyale.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/fire.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/ice.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/vendetta.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/attednev.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/tmobile.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/bloodyprincess.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/jeskai.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/absurdity.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/forgotten.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/america.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/rgb.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/starbucks.png">
<img src="https://raw.githubusercontent.com/izcet/fractol/master/pics/rave.png">

<br>

### Features included:
Any and all of these can be adjusted live in combination with each other.
- Zoom in/out on a point with mouse scroll.
- Translate x and y with arrow keys.
- Cycle through the current color palette with D and F. *(Epilepsy Warning on this feature)*
- Change the color palette with A and D.
- Increase and Decrease the number of iterations with left and right click.
- (Julia Type Only) Live recalculate the fractol based on the mouse position.
- (Julia Type Only) Freeze / Resume motion.
- (Sierpinski Only) Display all steps, not just the last iteration.
![Sierpinski All Iterations](https://raw.githubusercontent.com/izcet/fractol/master/pics/sierpinskiall.png)
<br>

#### Tools used to generate the colors
- My [Testwindow](https://github.com/izcet/testwindow) project.
- My [Gradient Generator](https://github.com/izcet/gradient_gen).
