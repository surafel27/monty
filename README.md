<h1>The Monty language</h1>
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

<h1>Monty byte code files</h1>

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.

<h1>Compilation & Output</h1>
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

<b>Author: surafel fekadu Megiso</b>
