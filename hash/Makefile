# Makefile

CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2

# Имя исполняемого файла
TARGET := encrypt_decrypt

# Исходные файлы
SRCS := main.cpp

# Объектные файлы
OBJS := $(SRCS:.cpp=.o)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
 $(CXX) $(CXXFLAGS) $^ -o $@ -lcryptopp

# Правило для компиляции .cpp в .o
%.o: %.cpp
 $(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

# Очистка созданных файлов
clean:
 rm -f $(OBJS) $(TARGET)
