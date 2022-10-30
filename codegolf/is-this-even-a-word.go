/*

Your should write a program or function that takes a 4-character string as input and outputs a value indicating if the string is an English word or not. You are allowed to make mistakes in 15% of the provided testcases.

Input details:
Input is a 4-character string containing only the lowercase English letters (a-z).

Output details:
If the input is an English word you should output a boolean true or an integer 1.

If the input isn't an English word you should output a boolean false or an integer 0.

Word lists
list of 4-letter English words (2236 words)

list of 4-letter non-word strings (2236 strings)

The non-word list contains uniformly randomly generated letter sequences with the real words removed from them.

Testing
Your program or function should make no more than 15% mistakes on the given word lists together. That means you can give wrong output for 670 of the 4472 provided inputs.

You should post the testing program or function too so others could check your answer. The length of your testing program doesn't count into your submissions score.

Standard loopholes are disallowed.

Your program shouldn't use any external sources e.g. accessing web or reading from file.

This is code-golf so the shortest program or function wins.

*/

package main

import (
	"bufio"
	"strings"
)

func main() {
	assert(dictionary["abby"] == true)
	assert(dictionary["line"] == true)
	assert(dictionary["acme"] == true)
	assert(dictionary["wave"] == true)
	assert(dictionary["unix"] == true)

	assert(dictionary["zzzz"] == false)
	assert(dictionary["zzzy"] == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mkdict(s string) map[string]bool {
	m := make(map[string]bool)
	r := strings.NewReader(s)
	b := bufio.NewScanner(r)
	for b.Scan() {
		l := b.Text()
		l = strings.TrimSpace(l)
		if l == "" {
			continue
		}
		m[l] = true
	}
	return m
}

var dictionary = mkdict(words)

const words = `
abba
abbe
abby
abed
abel
abet
able
ably
abos
abut
aces
ache
acid
acme
acne
acre
acta
acts
adam
adds
aden
afar
agar
aged
agee
ager
ages
agog
ague
aida
aide
aids
aims
ainu
airs
airy
ajar
ajax
akin
alan
alar
alas
alba
alec
alee
alex
alfa
alga
ally
alma
alms
aloe
alps
also
alum
alva
amen
ames
amid
ammo
amok
amos
amyl
anal
andy
anew
anna
anne
anon
ansi
ante
anti
ants
anus
aped
apes
apex
apse
aqua
arab
arch
arco
arcs
area
ares
argo
arid
arms
army
arpa
arts
asia
asks
atom
atop
aunt
aura
auto
aver
avid
avis
aviv
avon
avow
away
awed
awls
awry
axed
axel
axer
axes
axis
axle
axon
ayes
babe
baby
bach
back
bade
bags
bail
bait
baja
bake
baku
bald
bale
bali
balk
ball
balm
band
bane
bang
bank
bans
barb
bard
bare
bark
barn
barr
bars
bart
base
bash
bask
bass
bath
bats
baud
bawl
bays
bead
beak
beam
bean
bear
beat
beau
beck
beds
beef
been
beep
beer
bees
beet
begs
bela
bell
belt
bely
bend
bent
benz
bern
bert
bess
best
beta
bets
bevy
bias
bibs
bide
bids
bien
bier
bike
bile
bilk
bill
bind
bing
bini
bins
bird
bite
bits
blab
bled
blew
blip
blob
bloc
blot
blow
blue
blum
blur
boar
boat
bobs
boca
bode
body
boer
bogs
bohr
boil
bois
bold
boll
bolt
bomb
bond
bone
bong
bonn
bony
boob
book
boom
boon
boor
boos
boot
bore
borg
born
bose
boss
both
bout
bowl
bows
boyd
boys
brae
brag
bran
bras
brat
bray
bred
brew
brie
brig
brim
brow
bryn
buck
budd
buds
buff
bugs
bulb
bulk
bull
bump
bums
bunk
buns
bunt
buoy
burl
burn
burp
burr
burt
bury
bush
buss
bust
busy
butt
buys
buzz
byrd
byte
cabs
cady
cafe
cage
cain
cake
calf
call
calm
came
camp
cane
cans
cant
cape
caps
card
care
carl
carp
carr
cars
cart
case
cash
cask
cast
cats
cave
cede
cell
celt
cent
cern
chad
chao
chap
char
chat
chef
chen
chew
chic
chin
chip
chit
chop
chou
chum
cite
city
clad
clam
clan
clap
claw
clay
clio
clip
clod
clog
clot
club
clue
cluj
coal
coat
coax
cobb
coca
cock
coco
code
cody
coed
cogs
cohn
coil
coin
coke
cold
cole
colt
comb
come
cone
cook
cool
coon
coop
cope
cops
copy
cord
core
cork
corn
cost
cosy
cots
cove
cowl
cows
cozy
crab
crag
cram
cray
cree
crew
crib
crop
crow
crud
crux
cruz
cuba
cube
cubs
cued
cues
cuff
cull
cult
cups
curb
curd
cure
curl
curs
curt
cusp
cute
cuts
cyst
czar
dada
dade
dads
dahl
dale
dali
daly
dame
damn
damp
dams
dana
dane
dare
dark
darn
dart
dash
data
date
dave
davy
dawn
days
daze
dead
deaf
deal
dean
dear
debt
deck
deed
deem
deep
deer
defy
dell
demo
dens
dent
deny
desk
deus
dewy
dial
dice
dido
died
diem
dies
diet
digs
dike
dill
dime
dims
dine
ding
dint
dion
dips
dire
dirt
disc
dish
disk
dive
dock
dodd
doer
does
doge
dogs
dole
doll
dome
done
dons
doom
door
dope
dora
dose
dote
dots
doug
dove
down
doze
drab
drag
dram
draw
drew
drip
drop
drug
drum
dual
dubs
duck
duct
duel
dues
duet
duke
dull
duly
dumb
dump
dune
dung
dunk
dunn
dupe
dusk
dust
duty
dyad
dyed
dyer
dyes
dyke
dyne
each
earl
earn
earp
ears
ease
east
easy
eats
ebbs
eben
echo
eddy
eden
edge
edit
edna
eels
egan
eggs
egos
eire
eked
ekes
elba
elks
ella
elms
else
emil
emit
emma
ends
enid
enos
envy
epic
eras
ergo
eric
erie
erik
eris
erne
eros
errs
espy
etch
even
ever
evil
ewen
ewes
exam
exec
exit
eyed
eyer
eyes
ezra
face
fact
fade
fags
fail
fain
fair
fake
falk
fall
fame
fang
fans
fare
farm
fast
fate
fats
faun
fawn
faze
fear
feat
feed
feel
fees
feet
fell
felt
fend
fern
fess
feud
fiat
fief
fife
figs
fiji
file
fill
film
find
fine
fink
finn
fins
fire
firm
fish
fisk
fist
fits
five
flag
flak
flam
flap
flat
flaw
flax
flea
fled
flee
flew
flex
flip
flit
flog
flop
flow
flue
flux
foal
foam
foci
foes
fogs
fogy
foil
fold
folk
fond
font
food
fool
foot
ford
fore
fork
form
fort
foss
foul
four
fowl
fran
frau
fray
fred
free
fret
frey
frog
from
frye
fuel
fuji
full
fume
fund
funk
furs
fury
fuse
fuss
fuzz
gags
gail
gain
gait
gale
gall
galt
game
gang
gape
gaps
garb
gary
gash
gasp
gate
gaul
gave
gawk
gaze
gear
geld
gels
gems
gene
gent
germ
gets
gift
gild
gill
gilt
gina
ginn
gino
gins
gird
girl
girt
gist
give
glad
glee
glen
glow
glue
glut
gnat
gnaw
goad
goal
goat
gobi
gods
goes
goff
gogh
gold
golf
gone
gong
good
goof
gore
gory
gosh
goto
gout
gown
grab
grad
gram
gray
greg
grew
grey
grid
grim
grin
grip
gris
grit
grow
grub
guam
gulf
gull
gulp
gums
guns
guru
gush
gust
guts
guys
gwen
gwyn
gyro
haag
haas
hack
hahn
hail
hair
hale
half
hall
halt
hams
hand
hang
hans
hard
hare
hark
harm
harp
hart
hash
hate
hats
haul
have
hawk
hays
haze
hazy
head
heal
heap
hear
heat
hebe
heck
heed
heel
heir
held
hell
helm
help
hemp
hems
hens
hera
herb
herd
here
hero
herr
hers
hess
hews
hick
hide
high
hike
hill
hilt
hind
hint
hips
hire
hiss
hits
hive
hoar
hoes
hoff
hogs
hold
hole
holm
holy
home
homo
hone
hood
hoof
hook
hoop
hoot
hope
hopi
hops
horn
hose
host
hour
howe
howl
hoyt
hubs
huck
hues
huey
huge
hugh
hugo
hull
hume
hump
hums
hung
hunk
huns
hunt
hurd
hurl
hurt
hush
husk
huts
hyde
hymn
ibex
ibid
ibis
iced
ices
icon
idea
idem
idle
idly
idol
ifni
igor
ills
illy
imps
inca
inch
indo
indy
inks
inns
into
ions
iota
iowa
iran
iraq
ires
iris
irks
irma
iron
isis
isle
itch
itel
item
ivan
jabs
jack
jade
jail
jake
jams
jane
jars
java
jaws
jazz
jean
jeep
jeer
jeff
jerk
jest
jets
jews
jigs
jill
joan
jobs
jody
joel
joes
jogs
john
join
joke
jolt
jose
jots
jove
joys
juan
judd
jude
judo
judy
jugs
july
jump
june
jung
junk
juno
jura
jure
jury
just
kahn
kali
kane
kant
karl
karp
kate
katz
keel
keen
keep
kemp
kent
kept
kern
kerr
keys
kick
kids
kiel
kiev
kill
kind
king
kink
kirk
kiss
kite
kits
klan
klux
knee
knew
knit
knob
knot
know
knox
koch
kong
kudo
kuhn
kurd
kurt
labs
lace
lack
lacy
lads
lady
lags
laid
lain
lair
lake
lamb
lame
lamp
lana
land
lane
lang
laos
laps
lard
lark
lars
lash
lass
last
late
laue
lava
lawn
laws
lays
lazy
lead
leaf
leak
lean
leap
lear
leek
leer
lees
left
legs
lena
lend
lens
lent
leon
less
lest
lets
levi
levy
lewd
liar
lice
lick
lids
lied
lien
lies
lieu
life
lift
like
lila
lily
lima
limb
lime
limp
lind
line
link
lint
lion
lips
lisa
lise
lisp
liss
list
live
load
loaf
loan
lobe
loci
lock
loeb
loft
logo
logs
loin
lois
loki
lola
lomb
lome
lone
long
look
loom
loon
loop
loot
lord
lore
lose
loss
lost
lots
loud
lout
love
lowe
lows
luck
lucy
luis
luke
lull
lump
lund
lung
lura
lure
lurk
lush
lust
lute
lutz
lyle
lynn
lynx
lyon
lyra
lyre
mace
mach
made
maid
mail
maim
main
make
male
mali
mall
malt
mama
mane
mann
mans
many
maps
marc
mare
mark
mars
mart
marx
mary
mash
mask
mass
mast
mate
math
mats
matt
maul
mawr
maya
mayo
maze
mead
meal
mean
meat
meek
meet
melt
memo
mend
mens
menu
mere
mesh
mess
meta
mete
mets
mews
mica
mice
mick
mien
mike
mild
mile
milk
mill
mimi
mind
mine
mini
mink
mint
mips
mira
mire
miss
mist
moan
moat
mobs
mock
mode
moen
mohr
mold
mole
moll
mona
monk
mont
mood
moon
moor
moot
mops
more
morn
moss
most
moth
move
mows
much
muck
mudd
muff
mugs
muir
mule
mull
mung
muse
mush
musk
must
mute
mutt
muzo
myra
myth
nags
nagy
nail
nair
name
naps
nary
nasa
nash
nate
nato
naur
navy
nazi
neal
near
neat
neck
need
neff
neil
nell
neon
nero
ness
nest
nets
neva
news
newt
next
nice
nick
nigh
nile
nina
nine
nips
noah
node
nods
noel
noll
none
nook
noon
nora
norm
nose
note
noun
nude
null
numb
nuns
nuts
oaks
oars
oath
oats
obey
oboe
odds
odes
odin
odor
offs
ohio
oils
oily
okay
olaf
olav
oldy
oleg
olga
olin
oman
omen
omit
once
ones
only
onto
onus
onyx
ooze
opal
opec
opel
open
opts
opus
oral
ores
orgy
orin
orly
oslo
otis
otto
ouch
ours
oust
outs
oval
oven
over
ovid
owed
owen
owes
owls
owns
oxen
pace
pack
pact
pads
page
paid
pail
pain
pair
pale
pall
palm
palo
pals
pane
pang
pans
pant
papa
parc
pare
park
parr
pars
part
paso
pass
past
pate
path
pats
paul
pave
pawn
paws
pays
peak
peal
pear
peas
peat
peck
peek
peel
peep
peer
pegs
pelt
pend
penh
penn
pens
pent
perk
peru
pest
pete
pets
pews
phil
pica
pick
pict
pier
pies
pigs
pike
pile
pill
pimp
pine
ping
pink
pins
pint
pion
pipe
pisa
piss
pith
pits
pitt
pity
pius
plan
play
plea
plod
plot
plow
ploy
plug
plum
plus
pods
poem
poet
pogo
poke
pole
polk
poll
polo
pomp
pond
pong
pony
pool
poor
pope
pops
pore
pork
port
pose
posh
post
pots
pour
pout
pray
prep
prey
prim
prod
prop
pros
prow
pubs
puff
pugh
puke
pull
pulp
puma
pump
puns
punt
puny
pupa
pups
pure
purr
push
puss
puts
putt
pyle
pyre
quad
quay
quip
quit
quiz
race
rack
raft
rage
rags
raid
rail
rain
rake
ramo
ramp
rams
rand
rang
rank
rant
rape
raps
rapt
rare
rash
rasp
rate
rats
raul
rave
rays
raze
read
real
ream
reap
rear
redo
reds
reed
reef
reel
reid
rein
rely
remy
rena
rend
rene
reno
rent
rest
reub
rhea
ribs
rica
rice
rich
rick
rico
ride
rids
rift
riga
rigs
rill
rime
rims
rind
ring
rink
riot
ripe
rips
risc
rise
risk
rite
ritz
road
roam
roar
robe
robs
rock
rode
rods
role
roll
rome
romp
roof
rook
room
root
rope
rosa
rose
ross
rosy
roth
rots
rout
rove
rowe
rows
roxy
rube
rubs
ruby
rude
rudy
rugs
ruin
rule
rump
rung
runs
runt
rush
russ
rust
ruth
ruts
ryan
sack
safe
saga
sage
sags
said
sail
sake
sale
salk
salt
salz
same
sana
sand
sane
sang
sank
saps
sara
sari
sash
sate
saud
saul
save
saws
says
scab
scan
scar
scot
scow
scud
seal
seam
sean
sear
seas
seat
sect
seed
seek
seem
seen
seep
seer
sees
self
sell
semi
send
sent
sept
serf
seth
sets
sews
sexy
sham
shea
shed
shin
ship
shit
shod
shoe
shop
shot
show
shun
shut
siam
sian
sick
side
sift
sigh
sign
sikh
silk
sill
silo
silt
sims
sine
sing
sink
sins
sips
sire
sirs
site
sits
situ
siva
size
skew
skid
skim
skin
skip
skis
skit
skye
slab
slam
slap
slat
slav
slay
sled
slew
slid
slim
slip
slit
slob
slop
slot
slow
slug
slum
slur
smog
smug
smut
snag
snap
snip
snob
snow
snub
snug
soak
soap
soar
sobs
sock
soda
sods
sofa
soft
soil
sold
sole
solo
some
song
sons
sony
soon
soot
sore
sort
soul
soup
sour
sown
soya
span
spat
spec
sped
spin
spit
spot
spun
spur
stab
stag
stan
star
stay
stem
step
stew
stir
stop
stow
stub
stud
stun
styx
subs
such
suck
suds
sued
sues
suez
suit
sulk
sums
sung
sunk
suns
sure
surf
swab
swam
swan
swap
swat
sway
swim
swum
tabs
tack
tact
taft
tags
tail
take
tale
talk
tall
tame
tang
tank
taos
tape
taps
tara
tart
task
tass
tate
taut
taxi
team
tear
teas
teem
teen
tell
tend
tens
tent
term
tess
test
text
thai
than
that
thaw
thea
them
then
they
thin
this
thor
thud
thug
thus
tick
tide
tidy
tied
tier
ties
tile
till
tilt
time
tims
tina
tins
tint
tiny
tips
tire
tito
tits
toad
toby
todd
toes
togo
toil
told
toll
tomb
tone
toni
tons
took
tool
tops
tore
torn
tory
toss
toto
tour
town
toys
trap
tray
tree
trek
trim
trio
trip
trod
trot
troy
true
truk
tube
tubs
tuck
tuft
tugs
tune
turf
turn
twas
twig
twin
twos
type
typo
ugly
ulan
undo
unit
unix
unix
unto
upon
urdu
urge
uris
urns
ursa
used
user
uses
utah
vail
vain
vale
vane
vans
vary
vase
vast
vats
veal
veda
veer
vega
veil
vein
vela
venn
vent
vera
verb
vern
very
vest
veto
vial
vice
vida
vied
vier
vies
viet
view
vile
vine
visa
vita
vito
void
volt
voss
vote
vows
waco
wade
waft
wage
wags
wahl
wail
wait
wake
walk
wall
walt
wand
wane
wang
want
ward
ware
warm
warn
warp
wars
wart
wary
wash
wasp
wave
waxy
ways
weak
wean
wear
webb
webs
weds
weed
week
weep
wehr
weld
well
went
wept
were
west
wets
what
when
whim
whip
whit
whiz
whom
wick
wide
wier
wife
wigs
wild
wile
will
wilt
wily
wind
wine
wing
wink
wins
wipe
wire
wiry
wise
wish
wisp
with
wits
witt
woke
wolf
womb
wong
wont
wood
woof
wool
woos
word
wore
work
worm
worn
wove
wrap
wren
writ
wynn
yagi
yale
yank
yard
yarn
yawn
year
yeas
yell
yelp
yoke
york
yost
your
yuba
yuki
yuri
yves
zeal
zero
zest
zeus
zinc
zion
zone
zoom
zoos
zorn
zulu`