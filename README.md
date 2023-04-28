# ShareD

## Cloning

When cloning, add the `--recurse-submodules` parameter to the clone command.

## Dependencies

### Linux

```bash
// Development tools
sudo apt-get install build-essential
sudo apt-get install git
sudo apt-get install cmake

// Development libraries (nappgui)
sudo apt-get install libgtk-3-dev
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
sudo apt-get install libcurl4-openssl-dev

// Development libraries (Dlang deps)
sudo apt install libsqlite3-dev libssl-dev
```

## Building

```bash
dub run
```

## Notities

Dependencies voor de library opgehaald met
```bash
pkg-config --cflags --libs gtk+-3.0 | sed -e 's/ /", "/g' | sed -e 's/^/"/g' | sed -e 's/$/"/g'
```
en het resultaat in `dub.json` gestopt.

### Bouwen van _test_

> Vanuit de _test_ directory:

```bash
g++ main.cpp -L../build/Debug/lib -L../nappgui/lib/gcc11_gtk3_x64/Release -lShareDFrontend -losapp -losgui -lgui -ldraw2d -lgeom2d -lcore -losbs -lsewer -linet `pkg-config --cflags --libs gtk+-3.0` 
```