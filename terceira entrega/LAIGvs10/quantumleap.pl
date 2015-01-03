/*******************************
* MAIN FUNCTIONS AND GAME LOOP *
*******************************/

:- include('output.pl').
:- include('boardmanip.pl').

emptyBoard([[' ',' ',' ',' ',' ','#','#','#','#'],
			[' ',' ',' ',' ',' ',' ','#','#','#'],
			[' ',' ',' ',' ',' ',' ',' ','#','#'],
			[' ',' ',' ',' ',' ',' ',' ',' ','#'],
			[' ',' ',' ',' ',' ',' ',' ',' ',' '],
			['#',' ',' ',' ',' ',' ',' ',' ',' '],
			['#','#',' ',' ',' ',' ',' ',' ',' '],
			['#','#','#',' ',' ',' ',' ',' ',' '],
			['#','#','#','#',' ',' ',' ',' ',' ']
			]).

start(X) :-
	generateGameBoard(X),
	printBoard(X),
	playGame(X).

playGame(X) :-		
	player1turn(X, X1),
	printBoard(X1),
	player2turn(X1, X2),
	printBoard(X2),
	playGame(X2).

player1turn(Board1, Board2) :-
	write('\nJOGADOR 1\n'),
	write('Escolha a posicao da peca que pretende mover:\n'),
	write('X: '),
	read(Xpos),
	write('\n'),
	write('Y: '),
	read(Ypos),
	write('\n'),
	player1Stage2(Board1, Xpos, Ypos, Board2).

player1Stage2(Board1, X, Y, Board2) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece \== 'B',
	write('## Como Jogador 1, deve escolher uma peca PRETA (B) ##\n'),
	player1turn(Board1, Board2).

player1Stage2(Board1, X, Y, Board2) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece == 'B',
	write('Para onde pretende mover esta peca?\n'),
	write('X: '),
	read(Xdest),
	write('\n'),
	write('Y: '),
	read(Ydest),
	write('\n'),
	movePieceTo(Board1, X, Y, Xdest, Ydest, Board2).

player2turn(Board1, Board2) :-
	write('\nJOGADOR 2\n'),
	write('Escolha a posicao da peca que pretende mover:\n'),
	write('X: '),
	read(Xpos),
	write('\n'),
	write('Y: '),
	read(Ypos),
	write('\n'),
	player2Stage2(Board1, Xpos, Ypos, Board2).

player2Stage2(Board1, X, Y, Board2) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece \== 'W',
	write('## Como Jogador 2, deve escolher uma peca BRANCA (W) ##\n'),
	player1turn(Board1, Board2).

player2Stage2(Board1, X, Y, Board2) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece == 'W',
	write('Para onde pretende mover esta peca?\n'),
	write('X: '),
	read(Xdest),
	write('\n'),
	write('Y: '),
	read(Ydest),
	write('\n'),
	movePieceTo(Board1, X, Y, Xdest, Ydest, Board2).