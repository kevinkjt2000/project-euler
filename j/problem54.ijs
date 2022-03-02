require 'format/printf'

NB. returns 0 for tie
NB.         1 for player1 win
NB.         2 for player2 win
poker=: monad define
  'p1 p2'=: y
  p1=: /:~ p1
  p2=: /:~ p2

  a=: 2 =/\ {."1 p1
  qprintf 'p1 a '

  0
)


readfile=: 1!:1

filename=: < 'C:/Users/Kevin/Documents/code/project euler/p054_poker.txt'

file=: _29]\ LF -.~ readfile filename

cards=: ([: ,;._2 ,&' ')"1 file

hands=: _5]\"_1 cards

+/ 1&= poker"_1 hands