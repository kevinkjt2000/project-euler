require 'format/printf'

NB. R. E. Boss's comb implementation
comb=: 4 : 0
  if. x e. 0 1 do. z=.<((x!y),x)$ i.y
  else. t=. |.(<.@-:)^:(i.<. 2^.x)x
    z=.({.t) ([:(,.&.><@;\.)/ >:@-~[\i.@]) ({.t)+y-x
    for_j. 2[\t do.
      z=.([ ;@:(<"1@[ (,"1 ({.j)+])&.> ])&.> <@;\.({&.><)~ (1+({.j)-~{:"1)&.>) z
      if. 2|{:j do. z=.(i.1+y-x)(,.>:)&.> <@;\.z end.
    end.
  end.
  ;z
)

solve=: monad : 0
  primes=: ":"0 (#~ 99999&< *. <:&999999) p: i.80000
  n=: {. #"1 primes
  table=: ''
  for_i. }.i.n do.
    cs=: (i comb n)
    for_c. cs do.
      mask=: ([: *./ [: (= {.) c&{)"1 primes
      cands=: mask # primes
      cands=: '*' c}"1 cands
      freqs=: #/.~ cands
      top=: (,. \:~ freqs) ; (~.cands) \: freqs
      top=: {.&.> top
      table=: table , top
    end.
  end.
  table=: _2]\ table
  table \: 0 { |:table
)

{. solve ''