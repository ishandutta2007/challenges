#!/usr/bin/env python

description = """

Katlani is a constructed language being designed in chat. In this challenge, your goal is to print the largest dictionary of katlani nouns possible in 400 bytes or less.

Task

In 400 bytes or less, your program should print a list of katlani nouns. You can choose to output them as a list/array in your language, or as a string with any (not necessarily consistent) non-alphabetical separator, such as newlines or commas.
The capitalization and sorting of the words does not matter. Words not in the list are not allowed in the output, but duplicates are.

The list of nouns you may choose from are:

abail
abikis
ak
akniton
alfabit
atirsin
atom
ats
aypal
baka
baklait
banl
bgil
bianto
bit
bo
boraky
borsh
bot
br
brbrno
byt
daosik
diga
digiz
dogo
dolmuk
dongso
douv
drarkak
fa
fafasok
fasmao
fidr
floria
fridka
friv
fully
fylo
fyrus
gilmaf
gogu
gogzo
gongul
gorlb
gosio
gratbt
gutka
hisi
horrib
hurigo
inglish
iomshuksor
isa
ispikar
isplo
ita
iushb
izlash
kaikina
kat
katisas
katlani
kfaso
khalling
kisongso
kivsk
klingt
kod
koik
kolbat
komy
konma
korova
koss
kotsh
kris
kromir
ksik
ksuz
ktaf
ktomish
ktomizo
la
lan
lgra
loshad
lyly
mak
makanto
makav
makina
marinolus
marta
matiks
mim
mimhis
mingso
mitsh
molo
mosdob
motif
motkop
movogal
muratsh
mutka
naita
ngoirfo
nidriok
nilo
nin
nini
ninibr
nirus
noguna
nolif
nors
o
ogig
omkop
onion
opru
orilha
orni
ozon
papin
paslo
pasrus
pirishy
pluban
polr
posodo
pouk
produty
rak
raznitsa
rigiks
rilifior
riomr
rno
ronta
rus
ryby
sabbia
sai
sakar
saman
sandvitsh
sasa
sfiny
shatris
shidoso
shilan
shimshoom
shor
shotiya
shuan
shubhu
shuksor
shuriok
shutis
shutrak
shyba
sibas
sibin
simriomr
sod
sokit
spamra
spamt
srirad
sutka
taika
tipstor
tizingso
tksu
tobl
tokvod
tomp
tonfa
toto
totobr
tshans
tshimiso
tshomp
tura
tuvung
uboiak
umub
vaf
vintz
voda
vodl
vontark
y
yntsh
zimdo
zivod
zombit
zorliplak

Scoring

The winner (per language) is the answer that can print the largest number of unique words from the dictionary. Ties are broken by byte count, so if two answers manage to print all 200, the shorter of the two will win.

"""

def main():
    print(wordlist(description))

def wordlist(s):
    p = []
    l = s.split('\n')
    for t in l:
        if t == "" or t[0].isupper():
            continue
        u = t.split(' ')
        if len(u) == 1:
            p.append(u[0])
    return p

main()
