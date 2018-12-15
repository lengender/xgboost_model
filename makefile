CXX=g++
LINK_INC:=-I xgboost/include -I xgboost/rabit/include   $(LINK_INC)
LINK_LIB:=xgboost/lib/libxgboost.a xgboost/rabit/lib/librabit.a xgboost/dmlc-core/libdmlc.a $(LINK_LIB)


TARGET = test


all:${TARGET}

$(TARGET):main.o 
	$(CXX)  -o $@ main.o -fopenmp -Wall  $(LINK_INC) $(LINK_LIB)

main.o:main.cpp
	$(CXX) -c main.cpp $(LINK_INC)

clean:
	rm -rf *.o
	
