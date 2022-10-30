/*

Description
Your task is to implement a simple UNIX command parser and file system. Your program will have to implement a file system that can be modified via commands.

The starting directory of your file system is an empty root directory /, with no subdirectories or files. Your program must be capable of handling the following commands:

Commands
cd <dirpath> - Change the current directory

<dirpath> will be a list of directory names or "..", seperated by "/"
e.g. cd ../folder1/folder2 means to navigate up one directory level, then descend into folder1, then descend into folder2
If the directory path is not valid, then the command will do nothing
touch <filename> - Create a new file

e.g. touch me.txt creates a file called me.txt in the current directory
Filenames will only contain characters a-z and "."
Filenames will contain "." at least once
"." will never be the first or last character in a file name
If a file already exists with the same name in the current directory, nothing happens
mkdir <dirname> - Create a new directory

e.g. mkdir photos creates a new photos directory in the current directory
Directory names will only contan characters a-z
If a directory already exists with the same name in the current directory, nothing happens
rm [-r] <filename-or-dirname> - Remove a file or directory

e.g. rm hello.mp3 removes a file named hello.mp3 in the current directory
e.g. rm -r documents removes a folder named documents in the current directory, and all of its contents
If rm tries to delete a directory without the -r flag, nothing will happen
However rm will delete a file even with the -r flag
If the specified directory or file cannot be found, nothing happens
Tree output
Your program will output the following tree-like representation of the current file system using spaces as indentation. For example:

/
  documents
    document.docx
  downloads
    zippedfile
      notavirus.exe
    coolgoats.mp3
    zippedfile.zip
  pictures
    myvacation.png
All directories names must end with a "/" no longer necessary
You may use any number of spaces to indent the tree (minimum 1)
Directories must be listed before files in the same directory
Directories and files should be listed in lexographical alphabetical order
The character "." lexographically comes before any alphabetical character
You may output the contents of directories in any order you wish
Challenge
Create a program that accepts a series of commands, and outputs a tree-like representation of the current file system.

Input

The first line of input will be an integer N. Following will be N lines, each containing a command as described above.

You may feel free to omit the number N from your input if it is not necessary

Slight variations are allowed (using commas to seperate commands, input as a list etc) as long as it's reasonable

Output

The contents of the current file system in a tree-like representation, as described above.

Test Cases
Input 1: Simple example from earlier

15
mkdir documents
cd documents
touch document.docx
cd ..
mkdir downloads
cd downloads
touch coolgoats.mp3
touch zippedfile.zip
mkdir zippedfile
cd zippedfile
touch notavirus.exe
cd ../..
mkdir pictures
cd pictures
touch myvacation.png
Output 1:

/
  documents
    document.docx
  downloads
    zippedfile
      notavirus.exe
    coolgoats.mp3
    zippedfile.zip
  pictures
    myvacation.png
Input 2: Incorrect commands and edge cases

12
mkdir folder1
mkdir folder1
mkdir folder2
rm folder1
rm -r folder2
cd ..
cd ../folder1
cd folder1/folder2
touch file.txt
touch file.txt
touch file2.txt
rm -r file2.txt
Output 2:

/
  folder1
  file.txt
Input 3: Alphabetical listing of directories and files no longer necessary

8
mkdir b
mkdir c
mkdir a
touch c.txt
touch aa.txt
touch b.txt
touch a.txt
touch ab.txt
Output 3:

/
  a
  b
  c
  a.txt
  aa.txt
  ab.txt
  b.txt
  c.txt
Input 4: Partially correct cd should not be parsed (Suggested by @Arnauld)

4
mkdir folder1
cd folder1
cd ../folder2
touch file.txt
Output 4:

/
  folder1
    file.txt
Input 5: Partially correct cd should not be parsed (Suggested by @Abigail)

3
mkdir foo
cd bar/../foo
touch file.txt
Output 5:

/
  foo
  file.txt
Standard loopholes and I/O rules apply.

This is code-golf, shortest code wins.

Edit: output requirements have been relaxed a little bit

*/

package main

import (
	"bytes"
	"fmt"
	"io/fs"
	stdfs "io/fs"
	"os"
	stdpath "path"
	"sort"
	"strings"
)

func main() {
	test([]string{
		"mkdir documents",
		"cd documents",
		"touch document.docx",
		"cd ..",
		"mkdir downloads",
		"cd downloads",
		"touch coolgoats.mp3",
		"touch zippedfile.zip",
		"mkdir zippedfile",
		"cd zippedfile",
		"touch notavirus.exe",
		"cd ../..",
		"mkdir pictures",
		"cd pictures",
		"touch myvacation.png",
	})

	test([]string{
		"mkdir folder1",
		"mkdir folder1",
		"mkdir folder2",
		"rm folder1",
		"rm -r folder2",
		"cd ..",
		"cd ../folder1",
		"cd folder1/folder2",
		"touch file.txt",
		"touch file.txt",
		"touch file2.txt",
		"rm -r file2.txt",
	})

	test([]string{
		"mkdir b",
		"mkdir c",
		"mkdir a",
		"touch c.txt",
		"touch aa.txt",
		"touch b.txt",
		"touch a.txt",
		"touch ab.txt",
	})

	test([]string{
		"mkdir folder1",
		"cd folder1",
		"cd ../folder2",
		"touch file.txt",
	})

	test([]string{
		"mkdir foo",
		"cd bar/../foo",
		"touch file.txt",
	})

	test([]string{
		"mkdir bar",
		"cd bar",
		"touch a.txt",
		"cd ..///////..//../../.././..//../////../bar////..",
		"touch b.txt",
		"cd /bar/../bar/.",
		"touch c.txt",
	})

	test([]string{
		"touch x.txt",
		"touch x.txt/",
		"touch ../x.txt",
		"touch ../x.txt/",
		"touch ../y.txt/",
		"mkdir ../zzz/",
	})
}

func test(cmds []string) {
	fs := NewFS()
	for _, cmd := range cmds {
		fs.Execute(cmd)
	}
	fs.Dump()
}

type FS struct {
	cwd  string
	root *File
}

type File struct {
	name    string
	index   int
	mode    stdfs.FileMode
	entries []*File
}

var (
	ErrOperand      = fmt.Errorf("missing operand")
	ErrCommand      = fmt.Errorf("unknown command")
	ErrExist        = fmt.Errorf("file or directory already exist")
	ErrNotExist     = fmt.Errorf("no such file or directory")
	ErrDirectory    = fmt.Errorf("is a directory")
	ErrNotDirectory = fmt.Errorf("not a directory")
)

func NewFS() *FS {
	return &FS{
		cwd: "/",
		root: &File{
			mode: stdfs.ModeDir,
		},
	}
}

func (fs *FS) fullpath(path string) string {
	if !stdpath.IsAbs(path) {
		path = fs.cwd + "/" + path
	}

	buf := new(bytes.Buffer)
	slash := false
	for _, r := range path {
		if (r == '/' && !slash) || r != '/' {
			buf.WriteRune(r)
		}
		slash = (r == '/')
	}
	path = buf.String()

	return path
}

func (fs *FS) lookup(path string, mode int, perm fs.FileMode) (fullpath string, parent *File, file *File, err error) {
	if path == "" {
		err = ErrOperand
		return
	}

	fullpath = fs.fullpath(path)
	file = fs.root

	links := []*File{}
	names := strings.Split(fullpath, "/")
	bedir := false
	for len(names) > 0 && names[0] == "" {
		names = names[1:]
	}
	for len(names) > 0 && names[len(names)-1] == "" {
		names = names[:len(names)-1]
		bedir = true
	}

	for i, name := range names {
		if name == "." {
			continue
		}

		if name == ".." {
			parent = nil
			if nlinks := len(links); nlinks == 0 {
				file = fs.root
			} else {
				if nlinks >= 2 {
					parent = links[nlinks-2]
				}
				file = links[nlinks-1]
				links = links[:nlinks-1]
			}
			continue
		}

		parent = file
		links = append(links, parent)

		entries := file.entries
		nentries := len(entries)

		index := sort.Search(nentries, func(n int) bool {
			return strings.Compare(entries[n].name, name) >= 0
		})

		if index < nentries && entries[index].name == name {
			file = entries[index]
		} else {
			if i+1 < len(names) || mode&os.O_CREATE == 0 || (bedir && perm&stdfs.ModeDir == 0) {
				err = ErrNotExist
				return
			}

			file = &File{name: name, mode: perm}
			parent.entries = append(parent.entries, file)
			sort.Slice(parent.entries, func(i, j int) bool {
				return parent.entries[i].name < parent.entries[j].name
			})
			for i := range parent.entries {
				parent.entries[i].index = i
			}
		}

		if i+1 < len(names) && file.mode&stdfs.ModeDir == 0 {
			err = ErrNotExist
			return
		}
	}

	if bedir && file.mode&stdfs.ModeDir == 0 {
		err = ErrDirectory
		return
	}

	fullpath = stdpath.Clean(fullpath)
	return
}

func (fs *FS) cd(path string) error {
	fullpath, _, file, err := fs.lookup(path, 0, 0)
	if err != nil {
		return err
	}
	if file.mode&stdfs.ModeDir == 0 {
		return ErrNotDirectory
	}
	fs.cwd = fullpath
	return nil
}

func (fs *FS) touch(path string) error {
	_, _, _, err := fs.lookup(path, os.O_CREATE, 0)
	return err
}

func (fs *FS) mkdir(path string) error {
	_, _, file, err := fs.lookup(path, os.O_CREATE, stdfs.ModeDir)
	if err != nil {
		return err
	}
	if file.mode&stdfs.ModeDir == 0 {
		return ErrExist
	}
	return nil
}

func (fs *FS) rm(path string, recursive bool) error {
	_, parent, file, err := fs.lookup(path, 0, 0)
	if err != nil {
		return err
	}
	if !recursive && file.mode&stdfs.ModeDir != 0 {
		return ErrDirectory
	}
	parent.entries = append(parent.entries[:file.index], parent.entries[file.index+1:]...)
	return nil
}

func (fs *FS) Execute(cmd string) error {
	cmd = strings.Replace(cmd, "\t", " ", -1)
	toks := strings.Split(cmd, " ")
	if len(toks) < 2 {
		return ErrOperand
	}

	var err error
	switch toks[0] {
	case "cd":
		err = fs.cd(toks[1])
	case "touch":
		err = fs.touch(toks[1])
	case "mkdir":
		err = fs.mkdir(toks[1])
	case "rm":
		recursive := false
		name := toks[1]
		if len(toks) >= 3 && toks[1] == "-r" {
			recursive = true
			name = toks[2]
		}
		err = fs.rm(name, recursive)

	default:
		err = ErrCommand
	}

	return err
}

func (fs *FS) Dump() {
	fmt.Println("/")
	fs.walk(fs.root, 1)
}

func (fs *FS) walk(file *File, indent int) {
	entries := append([]*File{}, file.entries...)
	sort.Slice(entries, func(i, j int) bool {
		p := entries[i]
		q := entries[j]
		if p.mode&stdfs.ModeDir != 0 && q.mode&stdfs.ModeDir == 0 {
			return true
		}
		if p.mode&stdfs.ModeDir == 0 && q.mode&stdfs.ModeDir != 0 {
			return false
		}
		return p.name < q.name
	})

	for _, f := range entries {
		fmt.Printf(strings.Repeat(" ", indent*2))
		fmt.Print(f.name)
		if f.mode&stdfs.ModeDir != 0 {
			fmt.Print("/")
		}
		fmt.Println()

		fs.walk(f, indent+1)
	}
}
