#ifndef module_scanner_h
#define module_scanner_h

typedef enum
{
	// Single-character tokens.
	TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
	TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,
	TOKEN_COMMA, TOKEN_DOT, TOKEN_MINUS, TOKEN_PLUS,
	TOKEN_SEMICOLON, TOKEN_SLASH, TOKEN_STAR,

	// One or two character tokens.
	TOKEN_BANG, TOKEN_BANG_EQUAL,
	TOKEN_EQUAL, TOKEN_EQUAL_EQUAL,
	TOKEN_GREATER, TOKEN_GREATER_EQUAL,
	TOKEN_LESS, TOKEN_LESS_EQUAL,

	// Literals.
	TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_NUMBER,

	// Keywords.
	TOKEN_AND, TOKEN_CLASS, TOKEN_ABSTRACTION, TOKEN_IMPLEMENTATION,
	TOKEN_MUTABLE, TOKEN_INITILIZATION, TOKEN_PRIVATE,
	TOKEN_PUBLIC, TOKEN_ACCESSIBLE, TOKEN_ELSE, TOKEN_FALSE,
	TOKEN_FOR, TOKEN_FUNCTION, TOKEN_IF, TOKEN_NULL, TOKEN_OR,
	TOKEN_PRINT, TOKEN_RETURN, TOKEN_BASE, TOKEN_THIS,
	TOKEN_TRUE, TOKEN_LET, TOKEN_WHILE, TOKEN_ASYNC, TOKEN_PROPERTY,

	TOKEN_ERROR,
	TOKEN_EOF
} TokenType;

typedef struct
{
	TokenType type;
	const char* start;
	int length;
	int line;
} Token;

typedef struct
{
	const char* start;
	const char* current;
	int line;
} Scanner;

void initScanner(Scanner* scanner, const char* source);
Token scanToken(Scanner* scanner);

#endif