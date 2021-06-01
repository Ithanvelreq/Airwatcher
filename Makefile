CC=g++
CFLAGS=
EXEC=test

$(EXEC): Mesure.o DAO.o Utilisateur.o Provider.o Particulier.o Gouvernement.o Admin.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o Mesure.o DAO.o Utilisateur.o Provider.o Particulier.o Gouvernement.o Admin.o $(CFLAGS)

%.o: %.cpp %.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC).o: $(EXEC).cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o
