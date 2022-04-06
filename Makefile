ALL: part1 part2

part1:
	g++ -std=c++11 part1-fileconv.cpp -o part1 -lboost_serialization

part2:
	g++ -std=c++11 part2-dbmanip.cpp -o part2 -lboost_serialization

clean:
	rm part1 part2