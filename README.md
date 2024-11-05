This simple program is designed to quickly transfer something to a com device from the command line<br>

Usage:<br>
com hello - transmits hello to any available port <br>
com 4 hello - transmits hello to com4<br>

Installation:<br>
just move the program to the directory from which you will call it<br>

Example:<br>
if you open cmd using Run (Win+R), the path to the program should be:<br>
"C:\Users\Name\com.exe"<br>

Build:<br>
g++ com.cpp -o com.exe<br>
