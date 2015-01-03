/************************************************
* ALL STANDARD FUNCTIONS FOR BOARD MANIPULATION *
************************************************/

?- use_module(library(random)).

/* Empty board generation */
generateEmptyBoard(X) :- 
	generateEmptyBoardAux(L1, 1),
	generateEmptyBoardAux(L2, 2),
	generateEmptyBoardAux(L3, 3),
	generateEmptyBoardAux(L4, 4),
	generateEmptyBoardAux(L5, 5),
	generateEmptyBoardAux(L6, 6),
	generateEmptyBoardAux(L7, 7),
	generateEmptyBoardAux(L8, 8),
	generateEmptyBoardAux(L9, 9),
	append([], [L1], X1),
	append(X1, [L2], X2),
	append(X2, [L3], X3),
	append(X3, [L4], X4),
	append(X4, [L5], X5),
	append(X5, [L6], X6),
	append(X6, [L7], X7),
	append(X7, [L8], X8),
	append(X8, [L9], X).

generateEmptyBoardAux(L, N) :-
	N == 1,
	append([],[' ',' ',' ',' ',' ','#','#','#','#'],L).
generateEmptyBoardAux(L, N) :-
	N == 2,
	append([],[' ',' ',' ',' ',' ',' ','#','#','#'],L).
generateEmptyBoardAux(L, N) :-
	N == 3,
	append([],[' ',' ',' ',' ',' ',' ',' ','#','#'],L).
generateEmptyBoardAux(L, N) :-
	N == 4,
	append([],[' ',' ',' ',' ',' ',' ',' ',' ','#'],L).
generateEmptyBoardAux(L, N) :-
	N == 5,
	append([],[' ',' ',' ',' ',' ',' ',' ',' ',' '],L).
generateEmptyBoardAux(L, N) :-
	N == 6,
	append([],['#',' ',' ',' ',' ',' ',' ',' ',' '],L).
generateEmptyBoardAux(L, N) :-
	N == 7,
	append([],['#','#',' ',' ',' ',' ',' ',' ',' '],L).
generateEmptyBoardAux(L, N) :-
	N == 8,
	append([],['#','#','#',' ',' ',' ',' ',' ',' '],L).
generateEmptyBoardAux(L, N) :-
	N == 9,
	append([],['#','#','#','#',' ',' ',' ',' ',' '],L).

/* Game board generation */
generateGameBoard(X) :-
	genLine(1, L1),
	genLine(2, L2),
	genLine(3, L3),
	genLine(4, L4),
	genLine(5, L5),
	genLine(6, L6),
	genLine(7, L7),
	genLine(8, L8),
	genLine(9, L9),
	append([], [L1], X1),
	append(X1, [L2], X2),
	append(X2, [L3], X3),
	append(X3, [L4], X4),
	append(X4, [L5], X5),
	append(X5, [L6], X6),
	append(X6, [L7], X7),
	append(X7, [L8], X8),
	append(X8, [L9], X).
	
genLine(N, Line) :-
	N == 1,
	genLineAux(0, 4, [], LAux),
	append(LAux, ['#','#','#','#'], Line).
genLine(N, Line) :-
	N == 2,
	genLineAux(0, 5, [], LAux),
	append(LAux, ['#','#','#'], Line).
genLine(N, Line) :-
	N == 3,
	genLineAux(0, 6, [], LAux),
	append(LAux, ['#','#'], Line).
genLine(N, Line) :-
	N == 4,
	genLineAux(0, 7, [], LAux),
	append(LAux, ['#'], Line).
genLine(N, Line) :-
	N == 5,
	genLineAux(0, 8, [], LAux),
	append(LAux, [], Line).
genLine(N, Line) :-
	N == 6,
	genLineAux(0, 7, [], LAux),
	append(['#'], LAux, Line).
genLine(N, Line) :-
	N == 7,
	genLineAux(0, 6, [], LAux),
	append(['#','#'], LAux, Line).
genLine(N, Line) :-
	N == 8,
	genLineAux(0, 5, [], LAux),
	append(['#','#','#'], LAux, Line).
genLine(N, Line) :-
	N == 9,
	genLineAux(0, 4, [], LAux),
	append(['#','#','#','#'], LAux, Line).
	
genLineAux(N, FinalN, L1, L2) :- /* Generates line L2 with FinalN - 1 elements */
	N == FinalN,
	generateRandomPiece(NewPiece),
	append(L1,[NewPiece],L2).

genLineAux(N, FinalN, L1, L2) :-
	N < FinalN,
	N2 is N + 1,
	generateRandomPiece(NewPiece),
	append(L1, [NewPiece], LAux),
	genLineAux(N2, FinalN, LAux, L2).

/* Random piece generation */
generateRandomPiece(X) :-
	random(0, 2, N),
	returnPiece(N, X).

returnPiece(N, X) :-
	N == 0,
	X = 'B'.
returnPiece(N, X) :-
	N == 1,
	X = 'W'.

/* Game board access */
boardElementAt(Board, X, Y, Piece) :-
	boardLine(Board, 0, Y, Line),
	linePiece(Line, 0, X, Piece).

boardLine([B|Bs], N, Y, Line) :-
	N == Y,
	append([], B, Line).

boardLine([B|Bs], N, Y, Line) :-
	N < Y,
	N2 is N + 1,
	boardLine(Bs, N2, Y, Line).

linePiece([L|Ls], N, X, Piece) :-
	N == X,
	Piece = L.

linePiece([L|Ls], N, X, Piece) :-
	N < X,
	N2 is N + 1,
	linePiece(Ls, N2, X, Piece).

/* Board piece edit */
changePieceAt(Board1, X, Y, Piece, Board2) :-
	changePiece(Board1, 0, X, Y, Piece, Board2).

changePiece([B|Bs], N, X, Y, Piece, Board2) :-
	N == Y,
	changeLinePiece(B, 0, X, Piece, BoardAux),
	append([BoardAux], Bs, Board2).

changePiece([B|Bs], N, X, Y, Piece, Board2) :-
	N < Y,
	N2 is N + 1,
	changePiece(Bs, N2, X, Y, Piece, BoardAux),
	append([B], BoardAux, Board2).

changeLinePiece([L|Ls], N, X, Piece, L2) :-
	N == X,
	append([Piece], Ls, L2).

changeLinePiece([L|Ls], N, X, Piece, L2) :-
	N < X,
	N2 is N + 1,
	changeLinePiece(Ls, N2, X, Piece, Laux),
	append([L], Laux, L2).

/* Moving pieces */
movePieceTo(Board1, X1, Y1, X2, Y2, Board2) :-
	boardElementAt(Board1, X1, Y1, Piece),
	changePieceAt(Board1, X1, Y1, ' ', BoardAux),
	changePieceAt(BoardAux, X2, Y2, Piece, Board2).

/* Check valid plays */
getValidPlays(Board, X, Y, PlayList) :-
	boardElementAt(Board, X, Y, Piece).

checkPotential(Board, X, Y, N) :-
	boardElementAt(Board, X, Y, Piece),
	X1 is X + 1,
	Y1 is Y,
	checkPotentialAt(Board, Piece, X1, Y1, N, FinalN1), /* check right-side element */
	X2 is X - 1,
	Y2 is Y,
	checkPotentialAt(Board, Piece, X2, Y2, N, FinalN2), /* check left-side element */
	X3 is X,
	Y3 is Y - 1,
	checkPotentialAt(Board, Piece, X3, Y3, N, FinalN3), /* check upper element */
	X4 is X,
	Y4 is Y + 1,
	checkPotentialAt(Board, Piece, X4, Y4, N, FinalN4), /* check under element */
	X5 is X - 1,
	Y5 is Y - 1,
	checkPotentialAt(Board, Piece, X5, Y5, N, FinalN5), /* check first diagonal */
	X6 is X + 1,
	Y6 is Y + 1,
	checkPotentialAt(Board, Piece, X6, Y6, N, FinalN6), /* check second duagonal */
	FinalAux1 is FinalN1 + FinalN2,
	FinalAux2 is FinalAux1 + FinalN3,
	FinalAux3 is FinalAux2 + FinalN4,
	FinalAux4 is FinalAux3 + FinalN5,
	N is FinalAux4 + FinalN6.

checkPotentialAt(Board, Piece, X, Y, N, FinalN) :-
	boardElementAt(Board, X, Y, CheckPiece),
	CheckPiece == Piece,
	FinalN is N + 1.

checkPotentialAt(Board, Piece, X, Y, N, FinalN) :-
	boardElementAt(Board, X, Y, CheckPiece),
	CheckPiece \== Piece,
	FinalN is N.