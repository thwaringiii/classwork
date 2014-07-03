%
% hackers.pl
% CSE305
% Assignment 8 Question 1
% Thomas Waring III

% Julia Roberts learns Ruby
% Harrison Ford learns Javascript
% Daniel Craig learns Python
% Jack Nicholson learns Perl


solve(Ans):- 
   Ans = [triple(_,_,javascript), 
		triple(_,_,perl), 
		triple(_,_,python), 
		triple(_,_,ruby)], 
	
	% Ms Roberts will learn Ruby
		member(triple(_,roberts,ruby), Ans), 
		
	%Mr. Ford, Julia, and Jack Nicholson won't learn Python
		member(triple(_,ford,Lang1), Ans),
		member(triple(julia,_,Lang2), Ans),
		member(triple(jack,nicholson,Lang3), Ans),
		Lang1 \== python, Lang2 \== python, Lang3 \== python,
				
	%Harrison, who is not a Mr. Craig, will learn Javascript.
		member(triple(_,craig,_), Ans),
		member(triple(harrison,Last2,javascript), Ans),
		Last2 \== craig,
		
	%Daniel will not learn Perl.
		member(triple(daniel,_,Lang4), Ans),
		Lang4 \== perl,!.

	
   % Similarly, the other constraints become 1 or more goals 
   % involving member. Prolog's inequality predicate is \==
