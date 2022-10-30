open Printf

let rec factorial n = 
	if n <= 1 then
		1
	else
		n*factorial(n-1)
;;

let main() =
	if Array.length Sys.argv < 2 then begin
		print_string("usage: factorial <number> ...\n");
		exit 2;
	end;

	for i = 1 to Array.length Sys.argv-1 do
		let arg = int_of_string Sys.argv.(i) in
			print_string(Sys.argv.(i));
			printf(": ");
			print_int(factorial arg);
			print_newline();
	done;
	exit 0;
;;

main()
;;
