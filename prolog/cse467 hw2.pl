% Thomas Waring III
% CSE467 - Homework 2

% *****  Part 1  *****

% head to word to find correct tag.
tagit([],[]).
tagit([Word|Nextword],[Tag|Taglist]):- q0(Word,Tag), tagit(Nextword,Taglist).

q0([],[]).  % No words found?
q0(Word,Tag):- lemma(Word,Tag). % Already in the system. Done!
q0(Word,Tag):- append(Head,Tail,Word), lemma(Head,[cn,_]), q1(Tail,Tag).
q0(Word,Tag):- append(Head,Tail,Word), lemma(Head,[vb,_]), q2(Tail,Tag).


% Lemmas

lemma([a],[dt,s]).
lemma([a,l,l],[dt,p]).
lemma([e,a,c,h],[dt,s]).
lemma([m,a,n,y],[dt,p]).
lemma([m,o,s,t],[cn,p]).
lemma([t,h,e],[dt,_]).
lemma([t,h,e,y],[dt,p]).

lemma([d,o,g],[cn,s]).
lemma([c,a,t],[cn,s]).
lemma([r,a,t],[cn,s]).
lemma([c,h,e,e,s,e],[cn,s]).
lemma([p,e,o,p,l,e],[cn,p]).
lemma([m,i,c,e],[cn,p]).

lemma([e,a,t],[vb,t]).
lemma([c,h,a,s,e],[vb,t]).
lemma([l,i,k,e],[vb,t]).
lemma([d,i,e],[vb,i]).
lemma([s,n,e,e,z,e],[vb,i]).
lemma([a,t,e],[vb,t,pst]).

% Tense States

q1([],[cn,s]).
q1([s],[cn,p]).

q2([e,r|X],Y):- q1(X,Y).
q2([r|X],Y):- q1(X,Y).
q2([d],[vb,t,pst]).
q2([s],[vb,t,prs]).
q2([d],[vb,i,pst]).
q2([s],[vb,i,prs]).




% *****  PART 3  *****

calc_prob([],[]).
calc_prob([],1).
calc_prob(Word|[]],Total):-
			bigram(BigramValue, Word, s_end),
			word_total(WordValue,Word),
			probability(BigramValue, WordValue, Total).

calc_prob([Word1,Word2|NextWord], Total):-
			bigram(BigramValue, Word1, Word2),
			word_total(WordValue, Word1),
			probability(BigramValue, WordValue, Prob),
			calc_prob([Word2|NextWord], Recurse),!,
			multiply(Prob, Recurse, Total).
			
		
probability(B, W, P):- P is B / W.
multiply(B, W, T):- T is B * W.		


% Example bigrams and word totals.
% Full list for this assignment not included.

bigram(150,s_start,to).
bigram(200,to,the).
bigram(300,the,end).
bigram(400,end,s_end).
bigram( 432,from,the).
word_total(1100,s_start).
word_total(1200,of).
word_total(1800,the).
word_total(800,to).
word_total(1100,start).
word_total(1100,end).
word_total(1600,s_end).