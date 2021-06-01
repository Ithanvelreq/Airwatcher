CC=g++
CFLAGS=
#change for Maintest if you want to test the app
EXEC=Main

$(EXEC): Service.o Admin.o Gouvernement.o Provider.o Purificateur.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o Admin.o Attribut.o DAO.o Gouvernement.o Mesure.o Particulier.o Provider.o Purificateur.o Sensor.o Service.o Utilisateur.o $(CFLAGS)

Admin.o: Admin.cpp Admin.h Utilisateur.o

Attribut.o: Attribut.cpp Attribut.h 

DAO.o: DAO.cpp DAO.h Mesure.o Sensor.o Attribut.o Particulier.o 

Gouvernement.o: Gouvernement.cpp Gouvernement.h Utilisateur.o

Mesure.o: Mesure.cpp Mesure.h Attribut.o

Particulier.o: Particulier.cpp Particulier.h Utilisateur.o Sensor.o

Provider.o: Provider.cpp Provider.h Utilisateur.o Purificateur.o

Purificateur.o: Purificateur.cpp Purificateur.h

Sensor.o: Sensor.cpp Sensor.h

Service.o: Service.cpp Service.h DAO.o Mesure.o Sensor.o Particulier.o

Utilisateur.o: Utilisateur.cpp Utilisateur.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC).o: $(EXEC).cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o
