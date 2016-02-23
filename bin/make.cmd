cl ../*.c /Fe:test.exe
lib.exe /out:list.lib list.obj
cl /LD ../list.c /Fe:list.dll
