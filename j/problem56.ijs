digitsum =: ([: +/ [: "."0 ":)"0
answer =: >./@, digitsum ] (^/~ i.100x)
