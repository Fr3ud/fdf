# fdf
A simple 3D height-map renderer. You can rotate models, color is defined by relative height in the map.

### What is fdf?
[fdf][1] (which stand for "fil de fer" in French or Wire frame) is the first graphic project in [UNIT Factory][2] [(42)][3] using minilibx (Minilibx is a very basic graphical library writting in C used in [UNIT Factory][2] [(42)][3]).

The program take a map as arguments which content different number as their height and render it in 3D.
Mandatory part is **just** rendering and expose hook. All the other features are bonus.

### Features:
 - *Rotation X Y Z*
 - *Color gradients*
 - *Height modification*
 - *Onscreen telemetry*
 - *Window autosized from the map size*
 - *Map zoom according to the map size*

 ### Compiling and running:

 Run `make`. An executable will compile. Currently only tested on OS X.

 Run it with `./fdf [map]`. A bunch of sample maps are provided in the `maps`
 directory.

 Example (./fdf maps/42.fdf ):

    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
    0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
    0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
    0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
    0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
    0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
    0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

![fdf](/img/screen.png?raw=true)

[1]: https://github.com/Fr3ud/fdf/blob/master/fdf.en.pdf "fdf PDF"
[2]: https://unit.ua/ "UNIT Factory"
[3]: http://www.42.fr/ "42"
