.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -g DMAP

LIBS += -lpthread

PROGS = main.o Measure.o Utilisateurs.o Entreprise.o GouvernmentalAgency.o Individual.o Sensor.o Area.o Catalogue.o Purificateur.o SimpleInterface.o 

Final : $(PROGS)
	$(CPP) -o $@ $^

%.o : %.cpp
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f $(PROGS) *.o