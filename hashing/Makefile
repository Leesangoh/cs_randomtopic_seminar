all: build/stl_unordered_map build/chaining build/quadratic_probing build/my_hash_table

build/stl_unordered_map: src/stl_unordered_map.cc Makefile src/template.c
	g++ -O2 -lm src/stl_unordered_map.cc -o build/stl_unordered_map -std=c++0x

build/chaining: src/chaining.cc Makefile src/template.c
	g++ -O2 src/chaining.cc src/SeparateChaining.cc src/SeparateChaining.h -o build/chaining

build/quadratic_probing: src/quadratic_probing.cc Makefile src/template.c
	g++ -O2 src/quadratic_probing.cc src/QuadraticProbing.cc src/QuadraticProbing.h -o build/quadratic_probing

build/my_hash_table: src/my_hash_table.cc Makefile src/template.c
	g++ -O2 src/my_hash_table.cc src/MyHashTable.cc src/MyHashTable.h -o build/my_hash_table

