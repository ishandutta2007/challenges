#!/usr/bin/php

/*

Welcome to cipher day!

write a program that can encrypt texts with an alphabetical caesar cipher. This cipher can ignore numbers, symbols, and whitespace.

for extra credit, add a "decrypt" function to your program!

*/

<?php
	while (($line = fgets(STDIN)) !== false)
		echo str_rot13($line);
?>
