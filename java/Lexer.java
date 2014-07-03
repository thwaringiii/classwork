package Lab1;

import java.io.*;

//some code given for assignment, case statements following '-' are my work, as well as surrounding methods.

public class Lexer {
	 
	static private char ch = ' ';
	static private char ident = ' ';
	static public int intValue = 0;
	static public double realValue = 0;

	static private Buffer buffer = new Buffer(new DataInputStream(System.in));
	static public int nextToken;

	public static int lex() {
		while (Character.isWhitespace(ch))
			ch = buffer.getChar();
		if (Character.isLetter(ch)) {
			ident = Character.toLowerCase(ch);
			ch = buffer.getChar();
			nextToken = Token.ID;
		} else if (Character.isDigit(ch)) {
			nextToken = getNumToken();		// intValue or realValue would be set
		} else {
			switch (ch) {
			case ';':
				nextToken = Token.SEMICOLON;
				break;
			case ',':
				
				nextToken = Token.COMMA;
				break;
			case '.':
				nextToken = Token.PERIOD;
				break;
			case '+':
				nextToken = Token.ADD_OP;
				break;
			case '-':
				nextToken = Token.SUB_OP;
				break;
			case '*':
				nextToken = Token.MULT_OP;
				break;
			case '/':
				nextToken = Token.DIV_OP;
				break;
			case '=':
				nextToken = Token.ASSIGN_OP;
				break;
			case '(':
				nextToken = Token.LEFT_PAREN;
				break;
			case ')':
				nextToken = Token.RIGHT_PAREN;
				break;
			default:
				error("Illegal character " + ch);
				break;
			}
			ch = buffer.getChar();
		}
		return nextToken;
	} // lex

	public int number() {
		return intValue;
	} // number

	public Character identifier() {
		return ident;
	} // letter

	public static void error(String msg) {
		System.err.println(msg);
		System.exit(1);
	} // error

	private static int getNumToken() {
		int num = 0;
		String real = new String();
		boolean isRealNum = false;
		do {
			num = num * 10 + Character.digit(ch, 10);
			ch = buffer.getChar();
		} while (Character.isDigit(ch));
		
		if (ch == '.'){
			int deci = 0;
			ch = buffer.getChar();
			do {
				deci = deci * 10 + Character.digit(ch, 10);
				ch = buffer.getChar();
			} while (Character.isDigit(ch));
			real = num + "." + deci;
			isRealNum = true;
		}
		
		if (isRealNum){
			realValue = Double.parseDouble(real);
			return Token.REAL_LIT;	
		} else {
			intValue = num;
			return Token.INT_LIT;
		}
	}	
	
} // Lexer

	




