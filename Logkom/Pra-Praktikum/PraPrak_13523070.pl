/* Bagian I */
/* Deklarasi Fakta */
/* pria(X) benar, jika x adalah pria */
pria(qika).
pria(shelby).
pria(barok).
pria(francesco).
pria(panji).
pria(aqua).
pria(eriq).
/* wanita(X) benar, jika x adalah wanita */
wanita(hinatsuru).
wanita(makio).
wanita(suma).
wanita(yennefer).
wanita(roxy).
wanita(suzy).
wanita(eve).
wanita(frieren).
wanita(ruby).
wanita(aihoshino).
/* usia(X, Y) benar, jika x berusia y tahun */
usia(hinatsuru,105).
usia(qika,109).
usia(makio,96).
usia(suma,86).
usia(panji,124).
usia(frieren,90).
usia(shelby,42).
usia(yennefer,61).
usia(barok,59).
usia(roxy,70).
usia(suzy,23).
usia(francesco,25).
usia(eve,5).
usia(aqua,66).
usia(ruby,63).
usia(eriq,69).
usia(aihoshino,48).
/* menikah(X,Y) benar, jika X menikah dengan Y */
menikah(qika, hinatsuru).
menikah(hinatsuru,qika).
menikah(makio,qika).
menikah(qika,makio).
menikah(qika,suma).
menikah(suma,qika).
menikah(barok,roxy).
menikah(roxy,barok).
menikah(suzy,francesco).
menikah(francesco,suzy).
menikah(panji,frieren).
menikah(frieren,panji).
menikah(ruby,eriq).
menikah(eriq,ruby).
/* anak(X,Y) benar, jika X adalah anak dari Y */
anak(shelby,qika).
anak(shelby,hinatsuru).
anak(yennefer,qika).
anak(yennefer,hinatsuru).
anak(barok,qika).
anak(barok,makio).
anak(suzy,barok).
anak(suzy,roxy).
anak(eve,suzy).
anak(eve,francesco).
anak(aqua,panji).
anak(aqua,frieren).
anak(ruby,panji).
anak(ruby,frieren).
anak(aihoshino,eriq).
anak(aihoshino,ruby).

/* Deklarasi Rules */

/* saudara(X,Y) : X adalah saudara kandung maupun tiri dari Y */
saudara(X, Y) :- anak(X, Parent), anak(Y, Parent), X \= Y.

/* saudaratiri(X,Y) : X adalah saudara tiri dari Y */
saudaratiri(X, Y) :-
    anak(X, Parent1), 
    anak(Y, Parent2), 
    X \= Y, 
    Parent1 = Parent2, 
    menikah(Parent1, Pasangan1), 
    menikah(Parent1, Pasangan2), 
    Pasangan1 \= Pasangan2, 
    anak(X, Pasangan1), 
    anak(Y, Pasangan2).

/* kakak(X,Y) : X adalah kakak dari Y (kakak kandung maupun tiri) */
kakak(X, Y) :- saudara(X, Y), usia(X, Ux), usia(Y, Uy), Ux > Uy.

/* keponakan(X,Y) : X adalah keponakan dari Y */
keponakan(X, Y) :- anak(X, Z), saudara(Z, Y).

/* mertua(X,Y) : X adalah mertua dari Y */
mertua(X, Y) :- menikah(Y, Z), anak(Z, X).

/* nenek(X,Y) : X adalah nenek dari Y */
nenek(X, Y) :- wanita(X), anak(Z, X), anak(Y, Z).

/* keturunan(X,Y) : X adalah keturunan dari Y (anak, cucu, dan seterusnya) */
keturunan(X, Y) :- anak(X, Y).
keturunan(X, Y) :- anak(X, Z), keturunan(Z, Y).

/* lajang(X) : X adalah orang yang tidak menikah */
lajang(X) :- pria(X), \+ menikah(X, _).
lajang(X) :- wanita(X), \+ menikah(X, _).

/* anakbungsu(X) : X adalah anak paling muda */
anakbungsu(X) :- saudara(X, _), \+ (saudara(Y, X), \+ (X = Y), \+ kakak(Y, X)).

/* anaksulung(X) : X adalah anak paling tua */
anaksulung(X) :- saudara(X, _), \+ (saudara(Y, X), \+ (X = Y), kakak(Y, X)).

/* yatimpiatu(X) : X adalah orang yang orang tuanya tidak terdefinisi */
yatimpiatu(X) :- 
    pria(X),
    \+ anak(X, _).
yatimpiatu(X) :- 
    wanita(X),
    \+ anak(X, _).

/* Bagian II */

/* Exponent */
% basis
exponent(A, 0, X) :-
    A > 0,
    X is 1.
% aturan
exponent(A, B, X) :-
    B > 0,
    B1 is B - 1,
    exponent(A, B1, X1),
    X is A * X1.

/* Growth */
/* Fungsi Antara */
/* is_prime */
is_prime(2).
is_prime(3).
is_prime(N) :-
    N > 3,
    N mod 2 =\= 0,
    \+ has_factor(N, 3).

/* has_factor */
has_factor(N, F) :-
    N mod F =:= 0.
has_factor(N, F) :-
    F * F < N,
    F2 is F + 2,
    has_factor(N, F2).

/* Fungsi growth */
growth(I, _, _, 0, I).
growth(I, G, H, T, X) :-
    T > 0,
    T1 is T - 1,
    growth(I, G, H, T1, X1),
    (   is_prime(T)
    ->  X is X1 + G
    ;   X is X1 - H
    ).

/* Si Imut Anak Nakal */
harvestFruits(N, Fruits, TreeNumber, FinalResults) :-
    TreeNumber =< N,
    update_fruits(TreeNumber, Fruits, UpdatedFruits),
    (UpdatedFruits =< 0 ->
        write('Si Imut pulang sambil menangis :('), nl,
        FinalResults = 0
    ;
        NextTreeNumber is TreeNumber + 1,
        harvestFruits(N, UpdatedFruits, NextTreeNumber, FinalResults)
    ).
harvestFruits(_, Fruits, _, Fruits).
/* Hitung Buah */
update_fruits(TreeNumber, Fruits, UpdatedFruits) :-
    (TreeNumber mod 3 =:= 0 ->
        Fruits1 is Fruits + 2
    ; Fruits1 is Fruits),
    (TreeNumber mod 4 =:= 0 ->
        Fruits2 is Fruits1 - 5
    ; Fruits2 is Fruits1),
    (TreeNumber mod 5 =:= 0 ->
        Fruits3 is Fruits2 + 3
    ; Fruits3 is Fruits2),
    (is_prime(TreeNumber) ->
        UpdatedFruits is Fruits3 - 10
    ; UpdatedFruits is Fruits3).
    
/* KPK */
/* Fungsi FPB */
fpb(A, 0, A) :- A > 0.
fpb(A, B, X) :-
    B > 0,
    A1 is A mod B,
    fpb(B, A1, X).

/* Fungsi KPK */
kpk(A, B, X) :-
    fpb(A, B, F),
    X is (A * B) // F.

/* Factorial */
% basis
factorial(0, X) :- X is 1.

% aturan
factorial(N, X) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, X1),
    X is N * X1.

/* Make Pattern */
makePattern(N) :-
    between(1, N, I), % for i in range(1, N+1)
    makeRow(I, N),
    nl, % new line for every row
    flush_output, % flush output so nl works
    fail. % force backtrack
makePattern(_). % terminasi fungsi

makeRow(I, N) :-
    between(1, N, J), % for j in range(1, N+1)
    Depth is (min(min(I, J), min(N - I + 1, N - J + 1)) - 1) + 1, % pola tulisan +1 karena index dimulai dari 1
    write(Depth), % tampilkan ke layar
    fail. % force backtrack
makeRow(_, _). % terminasi fungsi

/* Bagian III */

/* List Statistic */
/* Comparator*/
lessthan(A, B, A) :- A =< B.
lessthan(A, B, B) :- A > B.
greaterthan(A, B, A) :- A >= B.
greaterthan(A, B, B) :- A < B.

/* min */
% basis
min([Min], Min).
% aturan
min([H | T], Min) :-
    min(T, MinT),
    lessthan(H, MinT, Min).

/* max */
% basis
max([Max], Max).
% aturan
max([H | T], Max) :-
    max(T, MaxT),
    greaterthan(H, MaxT, Max).

/* range */
% basis
range([Range], Range).
% aturan
range([H | T], Range) :-
    min([H, T], Min),
    max([H, T], Max),
    Range is Max - Min.

/* count */
% basis
count([], 0).
% aturan
count([_ | T], Count) :-
    count(T, CountT),
    Count is CountT + 1.

/* sum */
% basis
sum([], 0).
% aturan
sum([H | T], Sum) :-
    sum(T, SumT),
    Sum is SumT + H.

/* List Manipulation */
/* mergeSort */
mergeSort([], L, L).
mergeSort(L, [], L).
mergeSort([H1 | T1], [H2 | T2], Result) :-
    H1 < H2,
    mergeSort(T1, [H2 | T2], ResultT),
    Result = [H1 | ResultT].
mergeSort([H1 | T1], [H2 | T2], Result) :-
    H1 >= H2,
    mergeSort([H1 | T1], T2, ResultT),
    Result = [H2 | ResultT].

/* filterArray */
filterArray([], _, _, []).
filterArray([H | T], Element1, Element2, [H | Result]) :-
    H > Element1,
    H mod Element2 =:= 0,
    filterArray(T, Element1, Element2, Result).
filterArray([H | T], Element1, Element2, Result) :-
    (H =< Element1; H mod Element2 =\= 0),
    filterArray(T, Element1, Element2, Result).

/* reverseList */
reverseList(List, ReversedList) :-
    reverse_acc(List, [], ReversedList).
reverse_acc([], Acc, Acc).
reverse_acc([H | T], Acc, ReversedList) :-
    reverse_acc(T, [H | Acc], ReversedList).

/* cekPalindrom */
cekPalindrom(List) :-
    palindromeChecker(List, List).

/* palindromeChecker : Membandingkan List dengan Reversed List */
palindromeChecker([], []).
palindromeChecker([_], []).
palindromeChecker([H | T], ReversedList) :-
    listAppend(Rest, [H], ReversedList),
    palindromeChecker(T, Rest).

/* Menggabungkan List 1 dan List 2 */
listAppend([], L, L).
listAppend([H | T], L, [H | Result]) :-
    listAppend(T, L, Result).

/* rotate */
rotate([], _, []).
rotate(List, N, Result) :-
    length_acc(List, 0, Length),
    N1 is N mod Length,
    (N1 < 0 -> N2 is Length + N1; N2 is N1),
    rotate_left(List, N2, Result).

/* Menghitung length */
length_acc([], Acc, Acc).
length_acc([_ | T], Acc, Length) :-
    Acc1 is Acc + 1,
    length_acc(T, Acc1, Length).

/* Memutar List ke kiri */
rotate_left(List, 0, List).
rotate_left([H | T], N, Result) :-
    N > 0,
    N1 is N - 1,
    listAppend(T, [H], NewList),
    rotate_left(NewList, N1, Result).

/* Mapping */
/* Nilai Angka ke Huruf */
nilai_huruf(Nilai, 'A') :- Nilai >= 80.
nilai_huruf(Nilai, 'B') :- Nilai >= 70, Nilai < 80.
nilai_huruf(Nilai, 'C') :- Nilai >= 60, Nilai < 70.
nilai_huruf(Nilai, 'D') :- Nilai >= 50, Nilai < 60.
nilai_huruf(Nilai, 'E') :- Nilai < 50.

/* Status Kelulusan */
status_kelulusan(Average, 'Pass') :- Average >= 80.
status_kelulusan(Average, 'Fail') :- Average < 80.

/* Average */
average(List, Average) :-
    sum(List, Sum),
    listLength(List, Length),
    Length > 0,
    Average is Sum / Length.

/* List Length */
listLength(List, Length) :-
    length_acc(List, 0, Length).

/* Mengaitkan nilai ke huruf */
map_nilai([], []).
map_nilai([Nilai | T], [Huruf | T2]) :-
    nilai_huruf(Nilai, Huruf),
    map_nilai(T, T2).

/* Main */
prosesMahasiswa(Nama, NilaiAngka, Result) :-
    map_nilai(NilaiAngka, NilaiHuruf),
    average(NilaiAngka, RataRata),
    status_kelulusan(RataRata, Status),
    Result = [Nama, NilaiHuruf, RataRata, Status].

/* Bonus */
:- dynamic(koin/1).
/* start */
start :-
    \+ koin(_),
    retractall(koin(_)),
    asserta(koin(0)),
    write('Unta putih dan unta hitammu diambil oleh pedagang karavan. Kumpulkan koin sebanyak-banyaknya !!!'), nl, !.

start :- % Jika Permainan sudah dimulai
    koin(_),
    write('Permainan sudah dimulai. Gunakan "exit" untuk keluar dan memulai ulang.'), nl.

/* move */
move(Direction) :-
    koin(_),
    (Direction = north; Direction = south; Direction = east; Direction = west),
    write('Kamu bergerak ke arah '), write(Direction), write('.'), nl,
    random(0, 4, Result),
    (Result = 0 ->
        update_koin(-10),
        write('Oh tidak! Kamu terkena jebakan!'), nl
    ;
        update_koin(10),
        write('Jalannya aman.'), nl,
        write('Kamu mendapatkan 10 koin!'), nl
    ),
    koin(CurrentKoin),
    write('Koin Saat Ini: '), write(CurrentKoin), nl, !.

/* Coin Updater */
update_koin(Amount) :-
    koin(X),
    NewAmount is X + Amount,
    retract(koin(X)),
    asserta(koin(NewAmount)).

/* display_status */
display_status :-
    koin(Koin),
    write('Koin Saat Ini: '), write(Koin), nl.

/* exit */
exit :-
    koin(_),
    write('Terima kasih telah memainkan simulasi ini! Sampai jumpa lagi.'), nl,
    retractall(koin(_)), !.

exit :- 
    \+ koin(_),
    write('Permainan belum dimulai. Gunakan "start" untuk memulai.'), nl, fail.
