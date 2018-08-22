CXX = g++
CXXFLAGS = -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread
INCS = -I./ -I../../src -I/opt/gtest/include
OBJS = ../src/File.o File_Test.o 

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o testAll main_testAll.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm testAll *.o testAll.xml