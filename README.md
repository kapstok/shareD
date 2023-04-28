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

## Notes

https://nappgui.com/en/guide/resources.html
https://nappgui.com/en/start/start.html
https://dlang.org/spec/cpp_interface.html
https://dlang.org/phobos/std_string.html#.toStringz

Ik heb een aantal wijzigingen in de submodule gemaakt:

- CMakeFunctions.cmake aangepast en in de hoofddirectory gezet, maar die moet
dus in de module staan.
- Ik heb de shared library ook in `nappgui/bin/gcc11_gtk3_x64/Debug`,
`nappgui/lib/gcc11_gtk3_x64/Debug` en `nappgui/lib/gcc11_gtk3_x64/Release` gezet.
