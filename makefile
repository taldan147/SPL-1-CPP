all: cTrace

cTrace: bin/main.o bin/Session.o bin/JsonReader.o bin/Agent.o bin/Tree.o bin/Graph.o
	@echo 'Building target: cTrace'
	g++ -o bin/cTrace bin/main.o bin/Session.o bin/JsonReader.o bin/Agent.o bin/Tree.o bin/Graph.o
	@echo 'Finished building target: cTrace'
	@echo ' '

bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Session.o: src/Session.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp

bin/JsonReader.o: src/JsonReader.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/JsonReader.o src/JsonReader.cpp

bin/Agent.o: src/Agent.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp

bin/Tree.o: src/Tree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp

bin/Graph.o: src/Graph.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

bin/Tester.o: src/Tester.cpp
    g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tester.o src/Tester.cpp




clean:
	rm -f bin/*

