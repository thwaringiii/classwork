(*
 CSE305 - MAP.SML
 Assignment 7, Question 1
 Name: Thomas Waring III
*)

datatype color = red | green of int | blue of int | black of int*int | orange of string;

fun value(red) = 100
    | value(green(x)) = x*50
    | value(blue(x)) = x*25
    | value(black(x,y)) = x + y
    | value(orange(str)) = 111;

(*
  use above information as input for the below map
*)

fun map (f,[]) = []
    | map(f,h::t) = f(h) :: map(f,t)

(*
map - fn : ('a -> 'b) * 'a list -> 'b list
*)


fun square(x) = x*x;	(* int by default *)
val L1 = map(square, [1,2,3,4]);


(*define sqr_list in a function *)
fun sqr(x:int) = x*x;
fun sqr_map(input) =	let fun h(x) = sqr(x)
    		   	in map (h,input)
			end;

fun sqr2(x,y) = x*x+y;
fun sqr2_map(input, shift) =	let fun h(x) = sqr2(x,shift)
    		    	   	in map(h,input)
				end;


(*
val L2 = sqr_map([1,2,3,4]);
*)


(*
sqr_list = fn : int list -> int list
*)


fun reduce(f, b, []) = b
    | reduce(f, b, h::t) = f(h, reduce(f, b, t))


fun plus(x,y) = x+y;	 (* int type by default *)
val i = reduce(plus,0,[1,2,3,4,5]);



fun plus_reduce(input) = let fun h(x,y) = plus(x,y)
    		       	 in reduce (h,0,input)
		       	 end;