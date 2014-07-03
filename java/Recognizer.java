package Lab1;

/* 		OBJECT-ORIENTED RECOGNIZER FOR SIMPLE EXPRESSIONS
		  
   		expr    -> term   (+ | -) expr | term
   		term    -> factor (* | /) term | factor
   		factor  -> num  | realNum | '(' expr ')'     
*/

class Expr {    	// expr -> term (+ | -) expr | term
	Term t;
	Expr e;
	String op = "";
	String type;
	public void expr() throws ErrorHandling{
		t = new Term();
		t.term();
		this.type = t.type;
		if (Lexer.nextToken == Token.ADD_OP || 	
		    Lexer.nextToken == Token.SUB_OP) {
			op = Token.toString(Lexer.nextToken);
			Lexer.lex();
			e = new Expr();
			e.expr();
			if (this.type != e.type) {
				throw new ErrorHandling(this.type + "" + op + "" + e.type);
			}
		}
	}}

class Term {		// term -> factor (* | /) term | factor 
	Factor f;
	Term t;
	String op = "";
	String type;
	public void term() throws ErrorHandling{ 
		f = new Factor();
		f.factor();
		this.type = f.type;
		if (Lexer.nextToken == Token.MULT_OP || 
		    Lexer.nextToken == Token.DIV_OP) {
			op = Token.toString(Lexer.nextToken);
			Lexer.lex();
			t = new Term();
			t.term();
			if(this.type != t.type){
				throw new ErrorHandling(this.type + "" + op + "" + t.type);
			} 
		}
	}}

class Factor {		// factor -> num | realNum | '(' expr ')'
	Expr e;
	int i;
	double r;
	String type = "";
	//public void factor(String check) { 	
	public void factor() throws ErrorHandling{ 
		//String type = check;
		switch (Lexer.nextToken) {
		case Token.INT_LIT:    // number
			i = Lexer.intValue;
			Lexer.lex();
			type = "INT";
			break;
		case Token.REAL_LIT:
			r = Lexer.realValue;
			Lexer.lex();
			type = "REAL";
			break;
		case Token.LEFT_PAREN: // '('
			Lexer.lex();
			e = new Expr();
			e.expr();
			Lexer.lex();      // skip over ')'
			break;
		default:
			break;
			}
		}}

class ErrorHandling extends Exception{
	String errorh;
	public ErrorHandling (String msg) {
		super(msg);
		errorh = msg;
	}
	public String errorHandle(){
		return errorh;
	} // error
}