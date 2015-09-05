GEN_SRC := Something.cpp test_constants.cpp test_types.cpp FIFO.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR)

.PHONY: all clean

all: Something_server Something_client_uniform

%.o: %.cpp
	$(CXX) -std=c++11 -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -fpermissive -w -c $< -o $@

Something_server: Something_server.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift -L/usr/lib/x86_64-linux-gnu -lcurl

Something_client_uniform: Something_client_uniform.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift

clean:
	$(RM) *.o Something_server Something_client_uniform
