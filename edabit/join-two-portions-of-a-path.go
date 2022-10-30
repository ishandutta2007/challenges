/*

Write a function that receives two portions of a path and joins them. The portions will be joined with the "/" separator.
There could be only one separator and if it is not present it should be added.

Examples

joinPath("portion1", "portion2") ➞ "portion1/portion2"

joinPath("portion1/", "portion2") ➞ "portion1/portion2"

joinPath("portion1", "/portion2") ➞ "portion1/portion2"

joinPath("portion1/", "/portion2") ➞ "portion1/portion2"

Notes

Try not to solve this challenge using only if-else conditions.

*/

package main

import "path"

func main() {
	assert(joinpath("portion1", "portion2") == "portion1/portion2")
	assert(joinpath("portion1/", "portion2") == "portion1/portion2")
	assert(joinpath("portion1", "/portion2") == "portion1/portion2")
	assert(joinpath("portion1/", "/portion2") == "portion1/portion2")
	assert(joinpath("5wf7fny", "stJKXlc8") == "5wf7fny/stJKXlc8")
	assert(joinpath("5wf7fny/", "stJKXlc8") == "5wf7fny/stJKXlc8")
	assert(joinpath("5wf7fny", "/stJKXlc8") == "5wf7fny/stJKXlc8")
	assert(joinpath("5wf7fny/", "/stJKXlc8") == "5wf7fny/stJKXlc8")
	assert(joinpath("FKBZOBHo", "GNcYGnB") == "FKBZOBHo/GNcYGnB")
	assert(joinpath("FKBZOBHo/", "GNcYGnB") == "FKBZOBHo/GNcYGnB")
	assert(joinpath("FKBZOBHo", "/GNcYGnB") == "FKBZOBHo/GNcYGnB")
	assert(joinpath("FKBZOBHo/", "/GNcYGnB") == "FKBZOBHo/GNcYGnB")
	assert(joinpath("vL533Y3", "uVz3nul") == "vL533Y3/uVz3nul")
	assert(joinpath("vL533Y3/", "uVz3nul") == "vL533Y3/uVz3nul")
	assert(joinpath("vL533Y3", "/uVz3nul") == "vL533Y3/uVz3nul")
	assert(joinpath("vL533Y3/", "/uVz3nul") == "vL533Y3/uVz3nul")
	assert(joinpath("kfDOTwf", "Xr8viY8e") == "kfDOTwf/Xr8viY8e")
	assert(joinpath("kfDOTwf/", "Xr8viY8e") == "kfDOTwf/Xr8viY8e")
	assert(joinpath("kfDOTwf", "/Xr8viY8e") == "kfDOTwf/Xr8viY8e")
	assert(joinpath("kfDOTwf/", "/Xr8viY8e") == "kfDOTwf/Xr8viY8e")
	assert(joinpath("F4tBPmoV", "Lv18joOw") == "F4tBPmoV/Lv18joOw")
	assert(joinpath("F4tBPmoV/", "Lv18joOw") == "F4tBPmoV/Lv18joOw")
	assert(joinpath("F4tBPmoV", "/Lv18joOw") == "F4tBPmoV/Lv18joOw")
	assert(joinpath("F4tBPmoV/", "/Lv18joOw") == "F4tBPmoV/Lv18joOw")
	assert(joinpath("7ASOjVuT", "wwPOgKX") == "7ASOjVuT/wwPOgKX")
	assert(joinpath("7ASOjVuT/", "wwPOgKX") == "7ASOjVuT/wwPOgKX")
	assert(joinpath("7ASOjVuT", "/wwPOgKX") == "7ASOjVuT/wwPOgKX")
	assert(joinpath("7ASOjVuT/", "/wwPOgKX") == "7ASOjVuT/wwPOgKX")
	assert(joinpath("r1AiTrL", "KkyjD3K") == "r1AiTrL/KkyjD3K")
	assert(joinpath("r1AiTrL/", "KkyjD3K") == "r1AiTrL/KkyjD3K")
	assert(joinpath("r1AiTrL", "/KkyjD3K") == "r1AiTrL/KkyjD3K")
	assert(joinpath("r1AiTrL/", "/KkyjD3K") == "r1AiTrL/KkyjD3K")
	assert(joinpath("1h1gRAxu", "apQtQYgl") == "1h1gRAxu/apQtQYgl")
	assert(joinpath("1h1gRAxu/", "apQtQYgl") == "1h1gRAxu/apQtQYgl")
	assert(joinpath("1h1gRAxu", "/apQtQYgl") == "1h1gRAxu/apQtQYgl")
	assert(joinpath("1h1gRAxu/", "/apQtQYgl") == "1h1gRAxu/apQtQYgl")
	assert(joinpath("IYo5kuL", "QFEM6dSv") == "IYo5kuL/QFEM6dSv")
	assert(joinpath("IYo5kuL/", "QFEM6dSv") == "IYo5kuL/QFEM6dSv")
	assert(joinpath("IYo5kuL", "/QFEM6dSv") == "IYo5kuL/QFEM6dSv")
	assert(joinpath("IYo5kuL/", "/QFEM6dSv") == "IYo5kuL/QFEM6dSv")
	assert(joinpath("M6c7OnQI", "nj-CEAqV") == "M6c7OnQI/nj-CEAqV")
	assert(joinpath("M6c7OnQI/", "nj-CEAqV") == "M6c7OnQI/nj-CEAqV")
	assert(joinpath("M6c7OnQI", "/nj-CEAqV") == "M6c7OnQI/nj-CEAqV")
	assert(joinpath("M6c7OnQI/", "/nj-CEAqV") == "M6c7OnQI/nj-CEAqV")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func joinpath(s, t string) string {
	return path.Join(s, t)
}
