@echo off



cl /c /Ox src/*.c 
link /SUBSYSTEM:WINDOWS /ENTRY:_entry *.obj gdi32.lib advapi32.lib user32.lib kernel32.lib  /OUT:snake.exe

del *.obj
start snake.exe