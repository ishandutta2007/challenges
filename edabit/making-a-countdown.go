/*

Create a function where given the number n to count down from, and some words str, return a countdown sequence as a string leading up to the words at the end.

Put a full stop after each number and uppercase and add an exclamation mark to the word. See the examples below for clarification!

Examples

countdown(10, "Blast Off") ➞ "10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!"

countdown(3, "go") ➞ "3. 2. 1. GO!"

countdown(5, "FIRE") ➞ "5. 4. 3. 2. 1. FIRE!"

Notes

    n will be a number greater than 0.
    str won't already include an exclamation mark.
    Don't include 0 in the countdown.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(countdown(10, "Blast Off") == "10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(3, "go") == "3. 2. 1. GO!")
	assert(countdown(5, "FIRE") == "5. 4. 3. 2. 1. FIRE!")
	assert(countdown(12, "watch out") == "12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(7, "fire") == "7. 6. 5. 4. 3. 2. 1. FIRE!")
	assert(countdown(16, "shoot") == "16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(28, "fire") == "28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. FIRE!")
	assert(countdown(14, "watch out") == "14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(29, "take down") == "29. 28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(8, "boom") == "8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(24, "blast off") == "24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(3, "boom") == "3. 2. 1. BOOM!")
	assert(countdown(16, "watch out") == "16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(16, "blast off") == "16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(24, "boom") == "24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(2, "watch out") == "2. 1. WATCH OUT!")
	assert(countdown(1, "shoot") == "1. SHOOT!")
	assert(countdown(16, "go") == "16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. GO!")
	assert(countdown(26, "watch out") == "26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(5, "blast off") == "5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(26, "go") == "26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. GO!")
	assert(countdown(29, "go") == "29. 28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. GO!")
	assert(countdown(26, "shoot") == "26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(25, "watch out") == "25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(16, "blast off") == "16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(21, "take down") == "21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(23, "take down") == "23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(5, "fire") == "5. 4. 3. 2. 1. FIRE!")
	assert(countdown(13, "blast off") == "13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(1, "boom") == "1. BOOM!")
	assert(countdown(15, "shoot") == "15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(12, "shoot") == "12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(3, "take down") == "3. 2. 1. TAKE DOWN!")
	assert(countdown(27, "fire") == "27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. FIRE!")
	assert(countdown(17, "shoot") == "17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(17, "take down") == "17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(17, "watch out") == "17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(12, "shoot") == "12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(18, "take down") == "18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(8, "blast off") == "8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(15, "watch out") == "15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(18, "go") == "18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. GO!")
	assert(countdown(7, "boom") == "7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(23, "take down") == "23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(25, "take down") == "25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(28, "boom") == "28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(22, "shoot") == "22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(19, "boom") == "19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(30, "fire") == "30. 29. 28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. FIRE!")
	assert(countdown(28, "watch out") == "28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(26, "fire") == "26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. FIRE!")
	assert(countdown(12, "take down") == "12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(19, "boom") == "19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(30, "shoot") == "30. 29. 28. 27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(13, "fire") == "13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. FIRE!")
	assert(countdown(19, "blast off") == "19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(17, "take down") == "17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(1, "watch out") == "1. WATCH OUT!")
	assert(countdown(9, "shoot") == "9. 8. 7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(22, "take down") == "22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(4, "fire") == "4. 3. 2. 1. FIRE!")
	assert(countdown(7, "shoot") == "7. 6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(19, "blast off") == "19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(6, "go") == "6. 5. 4. 3. 2. 1. GO!")
	assert(countdown(20, "boom") == "20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(12, "boom") == "12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(20, "boom") == "20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BOOM!")
	assert(countdown(27, "take down") == "27. 26. 25. 24. 23. 22. 21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. TAKE DOWN!")
	assert(countdown(6, "blast off") == "6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(6, "shoot") == "6. 5. 4. 3. 2. 1. SHOOT!")
	assert(countdown(19, "blast off") == "19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. BLAST OFF!")
	assert(countdown(15, "watch out") == "15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. WATCH OUT!")
	assert(countdown(4, "blast off") == "4. 3. 2. 1. BLAST OFF!")
	assert(countdown(21, "go") == "21. 20. 19. 18. 17. 16. 15. 14. 13. 12. 11. 10. 9. 8. 7. 6. 5. 4. 3. 2. 1. GO!")
	assert(countdown(5, "bang") == "5. 4. 3. 2. 1. BANG!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func countdown(n int, s string) string {
	w := new(bytes.Buffer)
	for ; n > 0; n-- {
		fmt.Fprintf(w, "%d. ", n)
	}
	fmt.Fprintf(w, "%s!", strings.ToUpper(s))
	return w.String()
}
