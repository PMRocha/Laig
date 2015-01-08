/*******************************
* MAIN FUNCTIONS AND GAME LOOP *
*******************************/

:-use_module(library(sockets)).

port(60070).

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
	port(Port),
	socket_server_open(Port, Socket),
	socket_server_accept(Socket, _Client, Stream, [type(text)]),
	write('Connection established\n'),
	generateGameBoard(X),
	printBoard(X),
	/* send initial board state */
	write('Sending initial state...\n'),
	sendInitialState(X, Stream),
	write('Starting game.\n'),
	playGame(X, Stream),
	socket_server_close(Socket).

playGame(X, Stream) :-
	player1turn(X, X1, Stream),
	printBoard(X1),
	player2turn(X1, X2, Stream),
	printBoard(X2),
	playGame(X2).

player1turn(Board1, Board2, Stream) :-
	write('\nJOGADOR 1\n'),
	write('Escolha a posicao da peca que pretende mover:\n'),
	write('X: '),
	read(Stream, Xpos),
	write('Received X pos: '), write(Xpos), write('\n'),
	write('Y: '),
	read(Stream, Ypos),
	write('Received Y pos: '), write(Ypos), write('\n'),
	player1Stage2(Board1, Xpos, Ypos, Board2, Stream).

player1Stage2(Board1, X, Y, Board2, Stream) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece \== 'B',
	write('## Como Jogador 1, deve escolher uma peca PRETA (B) ##\n'),
	player1turn(Board1, Board2).

player1Stage2(Board1, X, Y, Board2, Stream) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece == 'B',
	write('Para onde pretende mover esta peca?\n'),
	write('X: '),
	read(Stream, Xdest),
	write('Received X pos: '), write(Xdest), write('\n'),
	write('Y: '),
	read(Stream, Ydest),
	write('Received Y pos: '), write(Ydest), write('\n'),
	movePieceTo(Board1, X, Y, Xdest, Ydest, Board2).

player2turn(Board1, Board2, Stream) :-
	write('\nJOGADOR 2\n'),
	write('Escolha a posicao da peca que pretende mover:\n'),
	write('X: '),
	read(Stream, Xpos),
	write('Received X pos: '), write(Xpos), write('\n'),
	write('Y: '),
	read(Stream, Ypos),
	write('Received Y pos: '), write(Ypos), write('\n'),
	player2Stage2(Board1, Xpos, Ypos, Board2, Stream).

player2Stage2(Board1, X, Y, Board2, Stream) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece \== 'W',
	write('## Como Jogador 2, deve escolher uma peca BRANCA (W) ##\n'),
	player1turn(Board1, Board2, Stream).

player2Stage2(Board1, X, Y, Board2, Stream) :-
	boardElementAt(Board1, X, Y, Piece),
	Piece == 'W',
	write('Para onde pretende mover esta peca?\n'),
	write('X: '),
	read(Stream, Xdest),
	write('Received X pos: '), write(Xdest), write('\n'),
	write('Y: '),
	read(Stream, Ydest),
	write('Received Y pos: '), write(Ydest), write('\n'),
	movePieceTo(Board1, X, Y, Xdest, Ydest, Board2).

sendInitialState(X, Stream) :-
	write('Starting\n'),
	boardElementAt(X, 0, 0, Piece),
	format(Stream, '~q.~n', [Piece]),
	flush_output(Stream),
	write('Sent one\n'),
	boardElementAt(X, 1, 0, Piece1),
	format(Stream, '~q.~n', [Piece1]),
	flush_output(Stream),
	boardElementAt(X, 2, 0, Piece2),
	format(Stream, '~q.~n', [Piece2]),
	flush_output(Stream),
	boardElementAt(X, 3, 0, Piece3),
	format(Stream, '~q.~n', [Piece3]),
	flush_output(Stream),
	boardElementAt(X, 4, 0, Piece4),
	format(Stream, '~q.~n', [Piece4]),
	flush_output(Stream),
	write('Going great\n'),
	boardElementAt(X, 5, 0, Piece5),
	format(Stream, '~q.~n', [Piece5]),
	flush_output(Stream),
	boardElementAt(X, 6, 0, Piece6),
	format(Stream, '~q.~n', [Piece6]),
	flush_output(Stream),
	boardElementAt(X, 7, 0, Piece7),
	format(Stream, '~q.~n', [Piece7]),
	flush_output(Stream),
	boardElementAt(X, 8, 0, Piece8),
	format(Stream, '~q.~n', [Piece8]),
	flush_output(Stream),
	boardElementAt(X, 0, 1, Piece9),
	format(Stream, '~q.~n', [Piece9]),
	flush_output(Stream),
	boardElementAt(X, 1, 1, Piece10),
	format(Stream, '~q.~n', [Piece10]),
	flush_output(Stream),
	boardElementAt(X, 2, 1, Piece11),
	format(Stream, '~q.~n', [Piece11]),
	flush_output(Stream),
	boardElementAt(X, 3, 1, Piece12),
	format(Stream, '~q.~n', [Piece12]),
	flush_output(Stream),
	boardElementAt(X, 4, 1, Piece13),
	format(Stream, '~q.~n', [Piece13]),
	flush_output(Stream),
	boardElementAt(X, 5, 1, Piece14),
	format(Stream, '~q.~n', [Piece14]),
	flush_output(Stream),
	boardElementAt(X, 6, 1, Piece15),
	format(Stream, '~q.~n', [Piece15]),
	flush_output(Stream),
	boardElementAt(X, 7, 1, Piece16),
	format(Stream, '~q.~n', [Piece16]),
	flush_output(Stream),
	boardElementAt(X, 8, 1, Piece17),
	format(Stream, '~q.~n', [Piece17]),
	flush_output(Stream),
	boardElementAt(X, 0, 2, Piece18),
	format(Stream, '~q.~n', [Piece18]),
	flush_output(Stream),
	boardElementAt(X, 1, 2, Piece19),
	format(Stream, '~q.~n', [Piece19]),
	flush_output(Stream),
	boardElementAt(X, 2, 2, Piece20),
	format(Stream, '~q.~n', [Piece20]),
	flush_output(Stream),
	boardElementAt(X, 3, 2, Piece21),
	format(Stream, '~q.~n', [Piece21]),
	flush_output(Stream),
	boardElementAt(X, 4, 2, Piece22),
	format(Stream, '~q.~n', [Piece22]),
	flush_output(Stream),
	boardElementAt(X, 5, 2, Piece23),
	format(Stream, '~q.~n', [Piece23]),
	flush_output(Stream),
	boardElementAt(X, 6, 2, Piece24),
	format(Stream, '~q.~n', [Piece24]),
	flush_output(Stream),
	boardElementAt(X, 7, 2, Piece25),
	format(Stream, '~q.~n', [Piece25]),
	flush_output(Stream),
	boardElementAt(X, 8, 2, Piece26),
	format(Stream, '~q.~n', [Piece26]),
	flush_output(Stream),
	boardElementAt(X, 0, 3, Piece27),
	write('How about here\n'),
	format(Stream, '~q.~n', [Piece27]),
	flush_output(Stream),
	boardElementAt(X, 1, 3, Piece28),
	format(Stream, '~q.~n', [Piece28]),
	flush_output(Stream),
	boardElementAt(X, 2, 3, Piece29),
	format(Stream, '~q.~n', [Piece29]),
	flush_output(Stream),
	boardElementAt(X, 3, 3, Piece30),
	format(Stream, '~q.~n', [Piece30]),
	flush_output(Stream),
	boardElementAt(X, 4, 3, Piece31),
	format(Stream, '~q.~n', [Piece31]),
	flush_output(Stream),
	boardElementAt(X, 5, 3, Piece32),
	format(Stream, '~q.~n', [Piece32]),
	flush_output(Stream),
	boardElementAt(X, 6, 3, Piece33),
	format(Stream, '~q.~n', [Piece33]),
	flush_output(Stream),
	boardElementAt(X, 7, 3, Piece34),
	format(Stream, '~q.~n', [Piece34]),
	flush_output(Stream),
	boardElementAt(X, 8, 3, Piece35),
	format(Stream, '~q.~n', [Piece35]),
	flush_output(Stream),
	boardElementAt(X, 0, 4, Piece36),
	format(Stream, '~q.~n', [Piece36]),
	flush_output(Stream),
	boardElementAt(X, 1, 4, Piece37),
	format(Stream, '~q.~n', [Piece37]),
	flush_output(Stream),
	boardElementAt(X, 2, 4, Piece38),
	format(Stream, '~q.~n', [Piece38]),
	flush_output(Stream),
	boardElementAt(X, 3, 4, Piece39),
	format(Stream, '~q.~n', [Piece39]),
	flush_output(Stream),
	boardElementAt(X, 4, 4, Piece40),
	format(Stream, '~q.~n', [Piece40]),
	flush_output(Stream),
	boardElementAt(X, 5, 4, Piece41),
	format(Stream, '~q.~n', [Piece41]),
	flush_output(Stream),
	boardElementAt(X, 6, 4, Piece42),
	format(Stream, '~q.~n', [Piece42]),
	flush_output(Stream),
	boardElementAt(X, 7, 4, Piece43),
	format(Stream, '~q.~n', [Piece43]),
	flush_output(Stream),
	boardElementAt(X, 8, 4, Piece44),
	format(Stream, '~q.~n', [Piece44]),
	flush_output(Stream),
	boardElementAt(X, 0, 5, Piece45),
	format(Stream, '~q.~n', [Piece45]),
	flush_output(Stream),
	boardElementAt(X, 1, 5, Piece46),
	format(Stream, '~q.~n', [Piece46]),
	flush_output(Stream),
	boardElementAt(X, 2, 5, Piece47),
	format(Stream, '~q.~n', [Piece47]),
	flush_output(Stream),
	boardElementAt(X, 3, 5, Piece48),
	format(Stream, '~q.~n', [Piece48]),
	flush_output(Stream),
	boardElementAt(X, 4, 5, Piece49),
	format(Stream, '~q.~n', [Piece49]),
	flush_output(Stream),
	boardElementAt(X, 5, 5, Piece50),
	format(Stream, '~q.~n', [Piece50]),
	flush_output(Stream),
	boardElementAt(X, 6, 5, Piece51),
	format(Stream, '~q.~n', [Piece51]),
	flush_output(Stream),
	boardElementAt(X, 7, 5, Piece52),
	format(Stream, '~q.~n', [Piece52]),
	flush_output(Stream),
	boardElementAt(X, 8, 5, Piece53),
	format(Stream, '~q.~n', [Piece53]),
	flush_output(Stream),
	boardElementAt(X, 0, 6, Piece54),
	format(Stream, '~q.~n', [Piece54]),
	flush_output(Stream),
	boardElementAt(X, 1, 6, Piece55),
	format(Stream, '~q.~n', [Piece55]),
	flush_output(Stream),
	boardElementAt(X, 2, 6, Piece56),
	format(Stream, '~q.~n', [Piece56]),
	flush_output(Stream),
	boardElementAt(X, 3, 6, Piece57),
	format(Stream, '~q.~n', [Piece57]),
	flush_output(Stream),
	boardElementAt(X, 4, 6, Piece58),
	format(Stream, '~q.~n', [Piece58]),
	flush_output(Stream),
	boardElementAt(X, 5, 6, Piece59),
	format(Stream, '~q.~n', [Piece59]),
	flush_output(Stream),
	boardElementAt(X, 6, 6, Piece60),
	format(Stream, '~q.~n', [Piece60]),
	flush_output(Stream),
	boardElementAt(X, 7, 6, Piece61),
	format(Stream, '~q.~n', [Piece61]),
	flush_output(Stream),
	boardElementAt(X, 8, 6, Piece62),
	format(Stream, '~q.~n', [Piece62]),
	flush_output(Stream),
	boardElementAt(X, 0, 7, Piece63),
	format(Stream, '~q.~n', [Piece63]),
	flush_output(Stream),
	boardElementAt(X, 1, 7, Piece64),
	format(Stream, '~q.~n', [Piece64]),
	flush_output(Stream),
	boardElementAt(X, 2, 7, Piece65),
	format(Stream, '~q.~n', [Piece65]),
	flush_output(Stream),
	boardElementAt(X, 3, 7, Piece66),
	format(Stream, '~q.~n', [Piece66]),
	flush_output(Stream),
	boardElementAt(X, 4, 7, Piece67),
	format(Stream, '~q.~n', [Piece67]),
	flush_output(Stream),
	boardElementAt(X, 5, 7, Piece68),
	format(Stream, '~q.~n', [Piece68]),
	flush_output(Stream),
	boardElementAt(X, 6, 7, Piece69),
	format(Stream, '~q.~n', [Piece69]),
	flush_output(Stream),
	boardElementAt(X, 7, 7, Piece70),
	format(Stream, '~q.~n', [Piece70]),
	flush_output(Stream),
	boardElementAt(X, 8, 7, Piece71),
	format(Stream, '~q.~n', [Piece71]),
	flush_output(Stream),
	boardElementAt(X, 0, 8, Piece72),
	format(Stream, '~q.~n', [Piece72]),
	flush_output(Stream),
	boardElementAt(X, 1, 8, Piece73),
	format(Stream, '~q.~n', [Piece73]),
	flush_output(Stream),
	boardElementAt(X, 2, 8, Piece74),
	format(Stream, '~q.~n', [Piece74]),
	flush_output(Stream),
	boardElementAt(X, 3, 8, Piece75),
	format(Stream, '~q.~n', [Piece75]),
	flush_output(Stream),
	boardElementAt(X, 4, 8, Piece76),
	format(Stream, '~q.~n', [Piece76]),
	flush_output(Stream),
	boardElementAt(X, 5, 8, Piece77),
	format(Stream, '~q.~n', [Piece77]),
	flush_output(Stream),
	boardElementAt(X, 6, 8, Piece78),
	format(Stream, '~q.~n', [Piece78]),
	flush_output(Stream),
	boardElementAt(X, 7, 8, Piece79),
	format(Stream, '~q.~n', [Piece79]),
	flush_output(Stream),
	boardElementAt(X, 8, 8, Piece80),
	format(Stream, '~q.~n', [Piece80]),
	flush_output(Stream).