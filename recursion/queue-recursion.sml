(* This file contains some examples of queue recuersion in the *)
(* functional programming language SML *)


(* Computes n! (factorial) *)
fun fact n =
  let fun fact_helper (n, acc) =
	if n = 0
	then acc
	else fact_helper(n - 1, n * acc)
  in
      fact_helper(n, 1)
  end


(* Computes x power y *)
fun power (x, y) =
  let fun power_helper (x, y, acc) =
	if y = 0
	then acc
	else power_helper(x, y - 1, x * acc)
  in
      power_helper(x, y, 1)
  end


val fact0 = fact(0)
val fact5 = fact(5)
val power3_4 = power(3, 4)
