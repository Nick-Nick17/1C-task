CXX = g++
CXXFLAGS = -I./lib -std=c++11

# Определяем целевые файлы
TARGET = main
TEST_TARGET = test_solution

# Объектные файлы
OBJS = bin/main.o lib/bor.o
TEST_OBJS = tests/test_solution.o lib/bor.o

# Основная цель
all: $(TARGET)

# Сборка основной программы
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# Сборка тестовой программы
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) -o $(TEST_TARGET) $(TEST_OBJS)

# Правила для объектных файлов
bin/main.o: bin/main.cpp lib/bor.h
	$(CXX) $(CXXFLAGS) -c bin/main.cpp -o bin/main.o

lib/bor.o: lib/bor.cpp lib/bor.h
	$(CXX) $(CXXFLAGS) -c lib/bor.cpp -o lib/bor.o

tests/test_solution.o: tests/test_solution.cpp lib/bor.h
	$(CXX) $(CXXFLAGS) -c tests/test_solution.cpp -o tests/test_solution.o

# Очистка объектных файлов и исполняемых файлов
clean:
	rm -f bin/*.o lib/*.o tests/*.o $(TARGET) $(TEST_TARGET)

# Запуск программы или тестов в зависимости от аргумента
run: all
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean run test
