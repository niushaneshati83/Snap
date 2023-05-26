CC= g++ -std=c++11


all:snap.out
snap.out:main.o Driver.o Count_mission.o Distance_mission.o mission.o Time_mission.o
	$(CC) -o snap.out main.o Driver.o Count_mission.o Distance_mission.o mission.o Time_mission.o

main.o:main.cpp Driver.h Count_mission.h Distance_mission.h mission.h Time_mission.h
	$(CC) -c main.cpp

mission.o:mission.h mission.cpp 
	$(CC) -c mission.cpp

Time_mission.o:Time_mission.cpp Time_mission.h mission.h
	$(CC) -c Time_mission.cpp

Distance_mission.o:Distance_mission.cpp Time_mission.h mission.h
	$(CC) -c Distance_mission.cpp

Count_mission.o: Count_mission.cpp Count_mission.h mission.h
	$(CC) -c Count_mission.cpp

Driver.o: Driver.cpp Driver.h
	$(CC) -c Driver.cpp

clean:
	rm *.o

