# BrokenEyes
## Info
<b>BrokenEyes has one memory cell and has a size of a byte (0 to 255).</b>
## Basic Syntax
```
. -> print mem cell as char
, -> print mem cell as char with space
; -> print mem cell as char with \n
^ -> reset mem cell to 0
+ -> increment mem cell
- -> decrement mem cell
! -> break loop
[commands] -> loop. Note: if the value before [ is 0 then the loop will not be running. Try this to understand +[,+]
(cond_value){commands} -> if value is equal to condition value then commands in {} will execute
```
## Hello, World!
Hello, World! In my implementation.
```
hello.be
+[(72){.}(101){.}(108){..}(111){.}+]+[(44){,!}+]+[(32){.}(87){.}(111){.}(114){.}+]+[(108){.}+]+[(100){.}+]+[(33){.!}+]
```
I hope you will <s>suffer</s> enjoy it! ;)

