/*

For this challenge, you will be given an absolute path, and a "new" path (which can be absolute or relative), and you need to return the final path.

For example, if your current directory was /var/tmp/test:

my_dir or my_dir/ should return /var/tmp/test/my_dir

../../my_dir should return /var/my_dir

/my_dir/./ should return /my_dir

../../../../../ should return /

To be more pedantic:

A directory is a non-empty string consisting of alphanumeric characters and the symbols -,_, or .
A path is a list of 0 or more directories, separated using /. An absolute path starts with a /, a relative path does not. Paths can include an ending /.
You need to "resolve" the second path, given the first path.

The process of resolving is:

Test if the second path is relative. If so, then insert the absolute path's directories to the beginning of the second path.
If any of the directories is .., then remove it and the preceding directory. If it is the first directory, then simply remove it.
If any of the directories is ., then remove it.
Output the final absolute path. You should not output an ending /.
You do not need to handle incorrect input. The commands should work, whether or not the directories passed actually exist on your machine. You can assume that everything is a directory, even if it has an extension.

Test cases
Absolute      New          Output
"/a/b/c"      "d"       -> "/a/b/c/d"
"/a/b/c/"     "d"       -> "/a/b/c/d"
"/a/b/c/"     "d/"      -> "/a/b/c/d"
"/a/b/c"      "/d"      -> "/d"
"/a/b/c"      "/d/"     -> "/d"
"/../a/b/c/"  "d"       -> "/a/b/c/d"
"/a/../b/c/"  "d"       -> "/b/c/d"
"/a/b/../c"   "d"       -> "/a/c/d"
"/a/b/c/.."   "d"       -> "/a/b/d"
"/a/b/c/"     ".."      -> "/a/b"
"/a/b/c"      "../d"    -> "/a/b/d"
"/a/b/c"      "/../d"   -> "/d"
"/a/b/c"      ""        -> "/a/b/c"
"/a/b/c"      "."       -> "/a/b/c"
"/a/b/c"      "./d"     -> "/a/b/c/d"
"/a/b/c"      "/./d"    -> "/d"
"/a/b/c"      "d.txt"   -> "/a/b/c/d.txt"
"/a/b/c"      "d."      -> "/a/b/c/d."
"/a/b/c"      ".txt"    -> "/a/b/c/.txt"
"/a/b/c"      ".txt/d"  -> "/a/b/c/.txt/d"
"/a/b/."      "./././." -> "/a/b"
"/direc"      "tory"    -> "/direc/tory"
"/a-_.b/"     "__._-."  -> "/a-_.b/__._-."
"/a/b"        "../.."   -> "/"
"/a/b"        "../../.."-> "/"
"/a"          "../../.."-> "/"
"/"           ""        -> "/"
"/"           "a"       -> "/a"
"/.."         "a"       -> "/a"
"/."          ""        -> "/"
This is a code-golf, so make your submissions as short as possible in your favorite language!

*/

package main

import "path"

func main() {
	assert(finalpath("/a/b/c", "d") == "/a/b/c/d")
	assert(finalpath("/a/b/c/", "d") == "/a/b/c/d")
	assert(finalpath("/a/b/c/", "d/") == "/a/b/c/d")
	assert(finalpath("/a/b/c", "/d") == "/d")
	assert(finalpath("/a/b/c", "/d/") == "/d")
	assert(finalpath("/../a/b/c/", "d") == "/a/b/c/d")
	assert(finalpath("/a/../b/c/", "d") == "/b/c/d")
	assert(finalpath("/a/b/../c", "d") == "/a/c/d")
	assert(finalpath("/a/b/c/..", "d") == "/a/b/d")
	assert(finalpath("/a/b/c/", "..") == "/a/b")
	assert(finalpath("/a/b/c", "../d") == "/a/b/d")
	assert(finalpath("/a/b/c", "/../d") == "/d")
	assert(finalpath("/a/b/c", "") == "/a/b/c")
	assert(finalpath("/a/b/c", ".") == "/a/b/c")
	assert(finalpath("/a/b/c", "./d") == "/a/b/c/d")
	assert(finalpath("/a/b/c", "/./d") == "/d")
	assert(finalpath("/a/b/c", "d.txt") == "/a/b/c/d.txt")
	assert(finalpath("/a/b/c", "d.") == "/a/b/c/d.")
	assert(finalpath("/a/b/c", ".txt") == "/a/b/c/.txt")
	assert(finalpath("/a/b/c", ".txt/d") == "/a/b/c/.txt/d")
	assert(finalpath("/a/b/.", "./././.") == "/a/b")
	assert(finalpath("/direc", "tory") == "/direc/tory")
	assert(finalpath("/a-_.b/", "__._-.") == "/a-_.b/__._-.")
	assert(finalpath("/a/b", "../..") == "/")
	assert(finalpath("/a/b", "../../..") == "/")
	assert(finalpath("/a", "../../..") == "/")
	assert(finalpath("/", "") == "/")
	assert(finalpath("/", "a") == "/a")
	assert(finalpath("/..", "a") == "/a")
	assert(finalpath("/.", "") == "/")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func finalpath(cwd, dir string) string {
	if path.IsAbs(dir) {
		return path.Clean(dir)
	}
	return path.Join(cwd, dir)
}
