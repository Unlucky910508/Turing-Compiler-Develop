{% Sigma.st
 
  Compute sum = 1 + 2 + ... + n
 %}

% constant and variable declarations
var test: string
const n: int := 10
var sum: int
var index: int
var temp: real

% main statements
sum := 00123
temp := 0.001
for index: 1 .. n 
  sum := sum + index
end for
put "The result is "
put sum
skip

% loop
sum := 0
index := 1
loop
  sum := sum + index
  index := index + 1
  exit when index = n
end loop
put "The result "" is "
put sum
""