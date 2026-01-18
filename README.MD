## Clarification

1. For the first question’s testing, I asked Claude to help me write some test cases. I told him the edge case. The content is as follows:

Please give me Google Test cases for the following code. The function is Slice

Basic
hello, 1, 3 -> el
hello, 0, 5 -> hello

end == 0 to end of string

hello, 2 -> llo
hello, 1, 0 -> ello

Indices like Python
hello, -2 -> lo
hello, 0, -1 -> hell
hello, -4, -1 -> ell

Out-of-range indices
hello, -100, 2  he
hello, 1, 100  ello
hello, 100, 0  ""

Empty
"", 0  ""
hello, 3, 1  ""

Because I found that prompting an AI to write tests takes more effort than just writing the tests myself, I wrote the tests on my own in the later parts.

2. For the Edit Distance question, I searched online and read:
https://www.geeksforgeeks.org/dsa/introduction-to-levenshtein-distance/
I referenced their second approach, but I modified it's logic and did not directly copy their code. I learned DP in the ECS122 course. I had done this problem before, but I forgot how to implement it now.

3. For the makefile a referenced the https://makefiletutorial.com/#makefile-cookbook