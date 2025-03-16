const test1 :int := 1111111111111
const test2 :real := 111.1111111
const test3 := "123"
const test5 :bool := true
const test6 :bool := true and false
const test7 :int := ((1 + 1) - 5 * 9 mod 100 + -11) / 5
var test8 := ((1+1)-5*9 mod 100 + 11) / 5
var test9 := false or true or false
var test10 :bool := not false
var test12: array 1..100 of real

function add(a :int, b :int) :int 
    result a + b
end add

procedure test11 (test12 :real, test13 :int)
    for decreasing i:100..1
        if 100 > 50 then
            return
        end if 

        if test12 > 50 then
            return
        end if

    end for

end test11

function multi(a :int, b :int) :int 
    result a * b
end multi

function pow(a :int, b :int) :int
    for i:1..b-1
        a = add(test[i], multi(a, a))
    end for
    
    result a
end pow

put "hello mother fuck"
put ((1+1)-5*9 mod 100 + 11) / 5
put (test1 + test2) * 100
get test14
