# Remove the '#' in line 2 if you want to check for memory leaks
CPPFLAGS = -std=c++11 -g #-fsanitize=address,leak,undefined
SRCS = main.cpp main_test.cpp Column.cpp Table.cpp
OBJS = $(SRCS:.cpp=.o)

ifeq (Windows_NT, $(OS))
RM_CMD := del /F
ZIP_CMD := zip
else
RM_CMD := rm -vf
ZIP_CMD := zip
endif


all: main

zinc: Table.cpp Column.cpp
	$(ZIP_CMD) pa1.zip $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -c $<

# To compile main.cpp, run "make" ====> "pa1.exe"
# To compile main_test.cpp, run "make main_test" ====> "pa1_test.exe"

main: Column.o Table.o main.o
	g++ $(CPPFLAGS) -o pa1.exe Column.o Table.o main.o

main_test: Column.o Table.o main_test.o
	g++ $(CPPFLAGS) -o pa1_test.exe Column.o Table.o main_test.o

clean:
	$(RM_CMD) *.o pa1.exe pa1_test.exe pa1.zip *.d

