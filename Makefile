.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -DMAP -g

LIBS += -lpthread

PROGS = main.o Catalogue.o Entreprise.o GouvernmentalAgency.o Sensor.o Individual.o Measure.o Purificateur.o Utilisateurs.o

Final : $(PROGS)
	$(CPP) -o $@ $^

%.o : %.cpp
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f $(PROGS) *.o