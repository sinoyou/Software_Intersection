# Software_Intersection
Repo for personal project of software engineer course in BUAA. 

Author: Zinuo You 17373321

Platform: Visual Studio 2019 x64

Function: Given N lines, count how many intersections existing. 

Running: exe file is located in bin directory, you can use `intersect.exe -i input_file -o output_file` to running.

IO Format:

- Input: 
  - A integer N $(1 \le N \le 500000)$ at first line: indicating how many geometry objects exists. 
  - Following N lines with format [L, x1, y1, x2, y2] to represent a line. (Must make sure that two points are different.)
- Output:
  - A integer M: number of intersection points. 
