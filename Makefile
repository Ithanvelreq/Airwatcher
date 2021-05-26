CC=g++
CFLAGS=
EXEC=test

$(EXEC): Mesure.o Service.o DAO.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o Mesure.o Service.o DAO.o$(CFLAGS)

%.o: %.cpp %.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC).o: $(EXEC).cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o
