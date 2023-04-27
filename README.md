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