
@echo OFF
FOR /L %%y IN (0, 1, 25000) DO (
a.exe
node main.js
)

pause