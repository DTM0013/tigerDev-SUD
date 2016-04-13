CC=g++
CFLAGS= -c -g -I../

LIBS=libs/Entity libs/Database libs/Combat


All: libraries

libraries:
	mkdir libraries/
	for dir in $(LIBS); do \
		cd $$dir; \
		$(CC) $(CFLAGS) *.cpp; \
		mv *.o ../../libraries; \
		cd -; \
	done
entity:
	cd libs/Entity; \
	$(CC) $(CFLAGS) Entity.cpp; \
	mv Entity.o ../../libraries;
	

character:
	cd libs/Entity/; \
	$(CC) $(CFLAGS) Character.cpp; \
	mv Character.o ../../libraries;

player:
	cd libs/Entity/; \
	$(CC) $(CFLAGS) Player.cpp; \
	mv Player.o ../../libraries;

room:
	cd libs/Entity/; \
	$(CC) $(CFLAGS) Room.cpp; \
	mv Room.o ../../libraries;

object:
	cd libs/Entity/; \
	$(CC) $(CFLAGS) Object.cpp; \
	mv Object.o ../../libraries;

equipment:
	cd libs/Entity/; \
	$(CC) $(CFLAGS) Equipment.cpp; \
	mv Equipment.o ../../libraries;

mapbuilder:
	cd libs/Database/; \
	$(CC) $(CFLAGS) MapBuilder.cpp; \
	mv MapBuilder.o ../../libraries;

skillbuilder:
	cd libs/Database/; \
	$(CC) $(CFLAGS) SkillBuilder.cpp; \
	mv SkillBuilder.o ../../libraries;

combat:
	cd libs/Combat/; \
	$(CC) $(CFLAGS) Combat.cpp; \
	mv Combat.o ../../libraries;

skill:
	cd libs/Combat/; \
	$(CC) $(CFLAGS) Skill.cpp; \
	mv Skill.o ../../libraries;
main:
	cd cli/; \
	$(CC) $(CFLAGS) -std=c++11 main.cpp; \
	mv main.o ../libraries;

executable:
	cd libraries; \
	g++ -std=c++11 -g -o run Character.o Combat.o Entity.o Equipment.o main.o MapBuilder.o Object.o Player.o Room.o Skill.o SkillBuilder.o; \
	mv run ../

clean:
	rm -rf libraries/
