# Lexical Analyzer

This project is a lexical analyzer for the C language. It is written mostly in C and uses the Flex library to generate the lexical analyzer.

# How to use
Make sure to have Flex installed on your system. Then, run the following commands:

1. Clone the repository
2. `cd` into the repository
3. Run `gcc lex.yy.c -ly -ll -o lexical-analyzer.out`
4. Run `./lexical-analyzer.out inputFile.txt`
5. The output will be in `lex_an_output.txt`

