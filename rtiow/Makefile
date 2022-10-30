CC=g++
CXXFLAGS=-Wall -Wextra -std=c++17
CXXFLAGS+=-march=native -O2
CXXFLAGS+=-Icommon/
LDFLAGS=-lpthread

SRC=

all: bin

bin:
	$(CC) $(CXXFLAGS) -o first-image 01-first-image/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o ray 02-ray/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o sphere 03-sphere/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o two-spheres 04-two-spheres/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o antialiasing 05-antialiasing/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o diffuse 06-diffuse/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o lambertian 07-lambertian/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o metal 08-metal/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o glass 09-glass/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o camera 10-camera/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o alternate-viewport 11-alternate-viewport/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o depth-of-field 12-depth-of-field/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o multiple-spheres 13-multiple-spheres/*.cpp $(SRC) $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o threaded-multiple-spheres 14-threaded-multiple-spheres/*.cpp $(SRC) $(LDFLAGS)

clean:
	rm -f first-image
	rm -f ray
	rm -f sphere
	rm -f two-spheres
	rm -f antialiasing
	rm -f diffuse
	rm -f lambertian
	rm -f metal
	rm -f glass
	rm -f camera
	rm -f alternate-viewport
	rm -f depth-of-field
	rm -f multiple-spheres
	rm -f threaded-multiple-spheres
	rm -f *.ppm
