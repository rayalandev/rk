pushd bin
cl /nologo /Wall /GR- /Zi ..\src\main.c /link opengl32.lib user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
popd